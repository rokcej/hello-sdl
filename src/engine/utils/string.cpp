#include "string.h"

namespace engine {

namespace string {

const char* FormatArg(const std::string& string) {
    return string.c_str();
}

const char* FormatArg(bool boolean) {
    return boolean ? "true" : "false";
}

} // namespace string

} // namespace engine
