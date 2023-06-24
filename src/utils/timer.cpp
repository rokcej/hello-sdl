#include "timer.h"

#include <SDL.h>

Timer::Timer() {
	ticks_start_ = SDL_GetTicks64();
	ticks_previous_ = ticks_start_;
	ticks_current_ = ticks_start_;
}

void Timer::Update() {
	ticks_previous_ = ticks_current_;
	ticks_current_ = SDL_GetTicks64();
}

float Timer::GetTime() const {
	return (ticks_current_ - ticks_start_) * 0.001f;
}

float Timer::GetDeltaTime() const {
	return (ticks_current_ - ticks_previous_) * 0.001f;
}
