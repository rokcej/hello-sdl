#include "system_manager.h"

#include "window_manager.h"
#include <SDL.h>
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
