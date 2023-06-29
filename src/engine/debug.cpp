#include "debug.h"

#include <iostream>
#include <cstdlib>

namespace engine::debug_internal {

void Assert(bool condition, const std::string& text) {
	if (!condition) {
		std::cerr << text << std::endl;
		std::abort();
	}
}

void Log(const std::string& text, bool error) {
	auto& out = error ? std::cerr : std::cout;
	out << text << std::endl;
}

} // namespace engine::debug_internal
