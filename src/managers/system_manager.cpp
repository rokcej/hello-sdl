#include "system_manager.h"

#include "manager_system.h"
#include "window_manager.h"
#include <SDL.h>
#include <backends/imgui_impl_sdl2.h>
#include <iostream>

SystemManager pSystemManager;

bool SystemManager::OnCreate() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	pWindowManager.CreateMainWindow(640, 480, "Hello SDL");

	return true;
}

void SystemManager::OnDestroy() {
	SDL_Quit();
}

void SystemManager::OnUpdate() {
	PollEvents();
}

void SystemManager::Sleep(unsigned int milliseconds) {
	SDL_Delay(milliseconds);
}

void SystemManager::PollEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		ImGui_ImplSDL2_ProcessEvent(&event);
		switch (event.type) {
		case SDL_QUIT: {
			ManagerSystem::GetInstance().Quit();
			break;
		}
		case SDL_WINDOWEVENT: {
			pWindowManager.OnWindowEvent(event.window);
			break;
		}
		}
	}
}
