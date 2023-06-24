#include <src/window.h>
#include <src/states/main_state.h>
#include <src/utils/timer.h>
#include <SDL.h>
#include <iostream>

int main(int argc, char* args[]) {
	Window window;
	if (!window.Init("Hello SDL", 640, 480)) {
		std::cerr << "Error initializing window" << std::endl;
		return 1;
	}

	Timer timer;
	MainState state;

	bool is_running = true;
	while (is_running) {
		timer.Update();

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				is_running = false;
			}
		}

		state.Update(timer.GetDeltaTime());
		state.Render();

		window.SwapBuffer();
		SDL_Delay(10); // Poor man's FPS limiter
	}

	return 0;
}
