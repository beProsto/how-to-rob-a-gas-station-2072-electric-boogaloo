
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void*
memcpy(void* dst, const void* src, size_t len)
{
  size_t i;

  if ((uintptr_t)dst % sizeof(long) == 0 &&
      (uintptr_t)src % sizeof(long) == 0 && len % sizeof(long) == 0) {
    long* d = (long*)dst;
    const long* s = (const long*)src;

    for (i = 0; i < len / sizeof(long); i++) {
      d[i] = s[i];
    }
  } else {
    char* d = (char*)dst;
    const char* s = (const char*)src;

    for (i = 0; i < len; i++) {
      d[i] = s[i];
    }
  }

  return dst;
}

void*
memset(void* dst, uint8_t data, size_t len)
{
  uint8_t* ptr = (uint8_t*)dst;

  for (; ptr < ((uint8_t*)dst) + len; ptr++) {
    *ptr = data;
  }

  return dst;
}

int
exported_function(int number)
{
  return number * 3;
}
