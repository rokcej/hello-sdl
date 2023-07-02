#pragma once

#include <engine/debug.h>
#include <string>
#include <cstdio>
#include <memory>

namespace engine {

namespace string {


// Convert custom arguments to const char*
template <typename T>
decltype(auto) FormatArg(const T& t) {
    return t;
}
const char* FormatArg(const std::string& string);
const char* FormatArg(bool boolean);


// Create string and insert arguments according to format specifiers
template <typename... Ts>
std::string Format(const std::string& format, const Ts&... args) {
    const int str_size = std::snprintf(nullptr, 0, format.c_str(), FormatArg(args)...);
    if (str_size < 0) {
        DEBUG_ASSERT(false, "Invalid string format");
        return std::string();
    }

    const size_t buf_size = static_cast<size_t>(str_size + 1);
    std::unique_ptr<char[]> buf(new char[buf_size]);
    std::snprintf(buf.get(), buf_size, format.c_str(), FormatArg(args)...);

    return std::string(buf.get(), buf.get() + str_size);
}


} // namespace string

} // namespace engine
