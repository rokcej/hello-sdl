#include "window.h"

#include <SDL.h>
#include <glad/glad.h>
#include <iostream>

Window::Window() {

}

Window::~Window() {
	SDL_GL_DeleteContext(sdl_gl_context_);
	SDL_DestroyWindow(sdl_window_);
}

bool Window::Init(const char* title, int width, int height) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	sdl_window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	if (!sdl_window_) {
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		return false;
	}

	sdl_gl_context_ = SDL_GL_CreateContext(sdl_window_);
	if (!sdl_gl_context_) {
		std::cerr << "Error creating SDL OpenGL context: " << SDL_GetError() << std::endl;
		return false;
	}

	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		std::cerr << "Error initializing GLAD" << std::endl;
		return false;
	}
}

void Window::SwapBuffer() {
	SDL_GL_SwapWindow(sdl_window_);
}

int Window::GetWidth() const {
	int width;
	SDL_GetWindowSize(sdl_window_, &width, nullptr);
	return width;
}

int Window::GetHeight() const {
	int height;
	SDL_GetWindowSize(sdl_window_, nullptr, &height);
	return height;
}

SDL_Window* Window::GetNativeWindow() const {
	return sdl_window_;
}

void* Window::GetNativeContext() const {
	return sdl_gl_context_;
}
