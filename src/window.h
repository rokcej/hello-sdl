#pragma once

struct SDL_Window;

class Window {
public:
	Window();
	~Window();

	bool Init(const char* title, int width, int height);
	void SwapBuffer();

	int GetWidth() const;
	int GetHeight() const;

	SDL_Window* GetNativeWindow() const;
	void* GetNativeContext() const;

private:
	SDL_Window* sdl_window_ = nullptr;
	void* sdl_gl_context_ = nullptr;

};
