#pragma once

#include <stddef.h>
#include <stdint.h>

// Memory Allocation
void*
malloc(size_t size);
void
free(void* ptr);
void*
calloc(size_t nmemb, size_t size);
// void*
// realloc(void* ptr, size_t size);

// Memory Values
void*
memcpy(void* dst, const void* src, size_t len);
void*
memset(void* dst, uint8_t data, size_t len);

// Strings (not quite sure about doing
//          this part as a whole, but
//          strlen is important!)
size_t
strlen(const char* _str);