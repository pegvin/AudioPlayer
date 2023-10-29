#include "imbase/window.hpp"
#include "imgui/imgui.h"

int main(void) {
	ImBase::Window::Init(320, 240, "AudioPlayer", false);
	ImBase::Window::SetMaxFPS(50);

	ImGuiIO& io = ImGui::GetIO();

	while (!ImBase::Window::ShouldClose()) {
		ImBase::Window::NewFrame();

		ImGui::SetNextWindowPos({ 0, 0 });
		ImGui::SetNextWindowSize(io.DisplaySize);
		if (ImGui::Begin("Main", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse)) {
			ImGui::Text("Hello World!");
			ImGui::End();
		}

		ImBase::Window::EndFrame();
	}

	ImBase::Window::Destroy();
	return 0;
}

