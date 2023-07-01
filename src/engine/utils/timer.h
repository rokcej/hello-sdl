#pragma once

namespace engine {

class Timer {
public:
	Timer();

	void Update();

	float GetTime() const;
	float GetDeltaTime() const;

private:
	unsigned long long ticks_start_;
	unsigned long long ticks_previous_;
	unsigned long long ticks_current_;

};

} // namespace engine
