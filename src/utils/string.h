#pragma once

#include <src/debug.h>
#include <string>
#include <cstdio>
#include <memory>

namespace string {

template <typename... Ts>
std::string Format(const std::string& format, Ts... args) {
    const int str_size = std::snprintf(nullptr, 0, format.c_str(), args...);
    if (str_size < 0) {
        DEBUG_ASSERT(false, "Invalid string format");
        return std::string();
    }

    const size_t buf_size = static_cast<size_t>(str_size + 1);
    std::unique_ptr<char[]> buf(new char[buf_size]);
    std::snprintf(buf.get(), buf_size, format.c_str(), args...);

    return std::string(buf.get(), buf.get() + str_size);
}

} // namespace string
