#include "debug.h"

#include <iostream>
#include <cstdlib>

namespace engine {

namespace debug {

void AssertInternal(bool condition, const std::string& text) {
	if (!condition) {
		std::cerr << text << std::endl;
		std::abort();
	}
}

void LogInternal(const std::string& text, bool error) {
	auto& out = error ? std::cerr : std::cout;
	out << text << std::endl;
}

} // namespace debug

} // namespace engine
