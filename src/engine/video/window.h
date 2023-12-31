#pragma once

#include <engine/utils/delegate.h>

struct SDL_Window;
struct SDL_WindowEvent;

namespace engine {

class Window {
	friend class WindowManager;

public:
	Window();
	~Window();

	bool Init(const char* title, int width, int height);
	void SwapBuffer();

	int GetWidth() const;
	int GetHeight() const;

	unsigned int GetId() const;
	SDL_Window* GetNativeWindow() const;
	void* GetNativeContext() const;

private:
	void OnWindowEvent(const SDL_WindowEvent& window_event);
	void UpdateFramebuffer();

public:
	Delegate<> OnSizeChangedDelegate;

private:
	int width_ = 0;
	int height_ = 0;

	SDL_Window* sdl_window_ = nullptr;
	void* sdl_gl_context_ = nullptr;

};

} // namespace engine
