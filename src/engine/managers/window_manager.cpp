#include "window_manager.h"

#include <engine/debug.h>
#include <SDL.h>
#include <iostream>

namespace engine {

WindowManager pWindowManager;

bool WindowManager::OnCreate() {
	return true;
}

void WindowManager::OnDestroy() {

}

bool WindowManager::CreateMainWindow(int width, int height, const char* title) {
	const bool success = windows_[0].Init(title, width, height);
	if (!success) {
		std::cerr << "Error initializing window" << std::endl;
		return false;
	}

	return true;
}

Window* WindowManager::GetMainWindow() {
	return &windows_[0];
}

Window* WindowManager::GetWindowById(unsigned int id) {
	for (auto& window : windows_) {
		if (id == window.GetId()) {
			return &window;
		}
	}
	return nullptr;
}

void WindowManager::OnWindowEvent(const SDL_WindowEvent& window_event) {
	Window* window = GetWindowById(window_event.windowID);
	if (window) {
		window->OnWindowEvent(window_event);
	}
	DEBUG_ASSERT(window, "Window events must have a valid window ID");
}

} // namespace engine
