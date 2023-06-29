#pragma once

#include <src/utils/string.h>

namespace engine {

	namespace debug_internal {

	// Private functions

	void Assert(bool condition, const std::string& text);
	void Log(const std::string& text, bool error);

	} // namespace debug_internal

// Public functions

template <typename... Ts>
void ASSERT(bool condition, const std::string& format, Ts... args) {
	debug_internal::Assert(condition, string::Format(format, args...));
}

template <typename... Ts>
void DEBUG_ASSERT(bool condition, const std::string& format, Ts... args) {
#if defined(BUILD_DEBUG)
	debug_internal::Assert(condition, string::Format(format, args...));
#endif
}

template <typename... Ts>
void LOG_INFO(const std::string& format, Ts... args) {
#if defined(BUILD_DEBUG)
	debug_internal::Log(string::Format(format, args...), false);
#endif
}

template <typename... Ts>
void LOG_ERROR(const std::string& format, Ts... args) {
#if defined(BUILD_DEBUG)
	debug_internal::Log(string::Format(format, args...), true);
#endif
}

} // namespace engine
