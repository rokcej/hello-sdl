#include "window.h"

#include <engine/debug.h>
#include <SDL.h>
#include <glad/glad.h>

namespace engine {

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

	width_ = width;
	height_ = height;

	const Uint32 flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
	sdl_window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	if (!sdl_window_) {
		LOG_ERROR("Error creating SDL window: %s", SDL_GetError());
		return false;
	}

	sdl_gl_context_ = SDL_GL_CreateContext(sdl_window_);
	if (!sdl_gl_context_) {
		LOG_ERROR("Error creating SDL OpenGL context: %s", SDL_GetError());
		return false;
	}

	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		LOG_ERROR("Error initializing GLAD");
		return false;
	}

	return true;
}

void Window::SwapBuffer() {
	SDL_GL_SwapWindow(sdl_window_);
}

void Window::OnWindowEvent(const SDL_WindowEvent& window_event) {
	switch (window_event.type) {
	case SDL_WINDOWEVENT_SIZE_CHANGED:
	case SDL_WINDOWEVENT_RESIZED: {
		const int new_width = static_cast<int>(window_event.data1);
		const int new_height = static_cast<int>(window_event.data2);
		if (new_width != width_ || new_height != height_) {
			width_ = new_width;
			height_ = new_height;
			UpdateFramebuffer();
		}
		break;
	}
	}
}

int Window::GetWidth() const {
	return width_;
}

int Window::GetHeight() const {
	return height_;
}

unsigned int Window::GetId() const {
	return SDL_GetWindowID(sdl_window_);
}

SDL_Window* Window::GetNativeWindow() const {
	return sdl_window_;
}

void* Window::GetNativeContext() const {
	return sdl_gl_context_;
}


void Window::UpdateFramebuffer() {
	glViewport(0, 0, width_, height_);
}

} // namespace engine
