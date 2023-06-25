#include <src/window.h>
#include <src/states/main_state.h>
#include <src/utils/timer.h>
#include <SDL.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>
#include <iostream>

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	Window window;
	if (!window.Init("Hello SDL", 640, 480)) {
		std::cerr << "Error initializing window" << std::endl;
		return 1;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForOpenGL(window.GetNativeWindow(), window.GetNativeContext());
	ImGui_ImplOpenGL3_Init();

	Timer timer;
	MainState state;

	bool is_running = true;
	while (is_running) {
		timer.Update();

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT) {
				is_running = false;
			} else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
				is_running = false;
			}
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame(window.GetNativeWindow());
		ImGui::NewFrame();

		state.Update(timer.GetDeltaTime());
		state.Render();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.SwapBuffer();
		SDL_Delay(1); // Poor man's FPS limiter
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_Quit();

	return 0;
}
