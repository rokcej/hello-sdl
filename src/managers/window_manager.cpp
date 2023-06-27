#include "window_manager.h"

#include <iostream>

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

Window& WindowManager::GetMainWindow() {
	return windows_[0];
}
