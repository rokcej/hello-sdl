#pragma once

#include <engine/utils/string.h>

namespace engine {

namespace debug {

void AssertInternal(bool condition, const std::string& text);
void LogInternal(const std::string& text, bool error);

} // namespace debug


template <typename... Ts>
void ASSERT(bool condition, const std::string& format, Ts... args) {
	debug::AssertInternal(condition, string::Format(format, args...));
}

template <typename... Ts>
void DEBUG_ASSERT(bool condition, const std::string& format, Ts... args) {
#if defined(BUILD_DEBUG)
	debug::AssertInternal(condition, string::Format(format, args...));
#endif
}

template <typename... Ts>
void LOG_INFO(const std::string& format, Ts... args) {
#if defined(BUILD_DEBUG)
	debug::LogInternal(string::Format(format, args...), false);
#endif
}

template <typename... Ts>
void LOG_ERROR(const std::string& format, Ts... args) {
#if defined(BUILD_DEBUG)
	debug::LogInternal(string::Format(format, args...), true);
#endif
}

} // namespace engine
