#pragma once

#include "manager.h"
#include <engine/video/window.h>
#include <array>

struct SDL_WindowEvent;

namespace engine {

class WindowManager : public Manager {
public:
	bool CreateMainWindow(int width, int height, const char* title = "");
	Window* GetMainWindow();
	Window* GetWindowById(unsigned int id);

	void OnWindowEvent(const SDL_WindowEvent& window_event);

protected:
	bool OnCreate() override;
	void OnDestroy() override;

private:
	std::array<Window, 1> windows_;

};

extern WindowManager pWindowManager;

} // namespace engine
