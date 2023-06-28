#include <src/states/main_state.h>
#include <src/utils/timer.h>
#include <src/managers/manager_system.h>
#include <src/managers/window_manager.h>
#include <src/managers/system_manager.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>
#include <iostream>

namespace imgui_utils {
void Create(const Window& window);
void Destroy();
void NewFrame(const Window& window);
void Render();
}

int main(int, char*[]) {
	ManagerSystem::GetInstance().Create();

	Window& window = pWindowManager.GetMainWindow();
	imgui_utils::Create(window);

	MainState state;

	Timer timer;
	while (!ManagerSystem::GetInstance().IsQuitting()) {
		imgui_utils::NewFrame(window);

		ManagerSystem::GetInstance().Update();
		timer.Update();
		state.Update(timer.GetDeltaTime());
		state.Render();

		imgui_utils::Render();

		window.SwapBuffer();
		pSystemManager.Sleep(1); // Poor man's FPS limiter
	}

	imgui_utils::Destroy();

	ManagerSystem::GetInstance().Destroy();

	return 0;
}

void imgui_utils::Create(const Window& window) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForOpenGL(window.GetNativeWindow(), window.GetNativeContext());
	ImGui_ImplOpenGL3_Init();
}

void imgui_utils::Destroy() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

void imgui_utils::NewFrame(const Window& window) {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(window.GetNativeWindow());
	ImGui::NewFrame();
}

void imgui_utils::Render() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
