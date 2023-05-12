#pragma once

void Core_PlaySound(const char* se, int unused);
void engine_printf(const char* fmt, ...);
unsigned int stringhash32(const char* str, size_t length);
unsigned int stringhash32(const char* str);

extern bool &bIsForegroundWindow;