#pragma once

#include <string>

void ASSERT(bool condition, const std::string& text);
void DEBUG_ASSERT(bool condition, const std::string& text);

void LOG_INFO(const std::string& text);
void LOG_ERROR(const std::string& text);
