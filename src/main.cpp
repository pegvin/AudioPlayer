#include "imbase/window.hpp"
#include "imgui/imgui.h"

int main(void) {
	ImBase::Window::Init(320, 240, "AudioPlayer", false);
	ImBase::Window::SetMaxFPS(50);

	while (!ImBase::Window::ShouldClose()) {
		ImBase::Window::NewFrame();

		ImGui::Text("Hello World!");

		ImBase::Window::EndFrame();
	}

	ImBase::Window::Destroy();
	return 0;
}

