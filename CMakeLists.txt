cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project(AudioPlayer C CXX)

file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.c)

# On Windows, Enable RC Language & Add It To Sources
if(WIN32)
	enable_language(RC)
	set(SRC_FILES ${SRC_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/data/windows.rc)
endif()

# Debug C/C++ flags
if(CMAKE_BUILD_TYPE STREQUAL Debug)
	if(NOT WIN32)
		add_compile_options(-fsanitize=address)
		add_link_options(-fsanitize=address)
	endif()
	add_definitions(-D_DEBUG)
else()
	add_definitions(-D_NDEBUG)
endif()

add_executable(AudioPlayer ${SRC_FILES})
target_include_directories(AudioPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/imbase/)
target_link_libraries(AudioPlayer PUBLIC imbase)

target_compile_options(AudioPlayer PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4>
	$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)

if(WIN32)
	add_custom_command(TARGET AudioPlayer POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:AudioPlayer> $<TARGET_RUNTIME_DLLS:AudioPlayer>
		COMMAND_EXPAND_LISTS
	)
endif()

