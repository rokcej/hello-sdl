#include "debug.h"

#include <iostream>
#include <cstdlib>

void ASSERT(bool condition, const std::string& text) {
	if (!condition) {
		std::cerr << text << std::endl;
		std::abort();
	}
}

void DEBUG_ASSERT(bool condition, const std::string& text) {
#if defined(BUILD_DEBUG)
	ASSERT(condition, text);
#endif
}

void LOG_INFO(const std::string& text) {
#if defined(BUILD_DEBUG)
	std::cout << text << std::endl;
#endif
}

void LOG_ERROR(const std::string& text) {
#if defined(BUILD_DEBUG)
	std::cerr << text << std::endl;
#endif
}
