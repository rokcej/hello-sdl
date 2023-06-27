#pragma once

#include "manager.h"
#include <src/window.h>
#include <array>

class WindowManager : public Manager {
public:
	bool CreateMainWindow(int width, int height, const char* title = "");
	Window& GetMainWindow();

protected:
	bool OnCreate() override;
	void OnDestroy() override;

private:
	std::array<Window, 1> windows_;

};

extern WindowManager pWindowManager;
