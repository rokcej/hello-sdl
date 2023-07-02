#include "debug.h"

#include <iostream>
#include <cstdlib>

namespace engine {

namespace debug {

void AssertInternal(bool condition, const std::string& text) {
	if (!condition) {
		std::cerr << "[ASSERT] " << text << std::endl;
		std::abort();
	}
}

void LogInternal(const std::string& text, bool error) {
	if (error) {
		std::cerr << "[ERROR] " << text << std::endl;
	} else {
		std::cout << "[INFO] " << text << std::endl;
	}
}

} // namespace debug

} // namespace engine
