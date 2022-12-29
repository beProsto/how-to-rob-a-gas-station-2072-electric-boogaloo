#include <env/print.h>

#include <stdarg.h>
#include <stddef.h>

// Our own printf
void
printf(const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  for (size_t i = 0; fmt[i] != '\0'; i++) {
    if (fmt[i] == '%') {
      i += 1;

      switch (fmt[i]) {
        case 's': {
          const char* str = va_arg(args, const char*);
          env_ps(str);
          continue;
        }
        case 'c': {
          char ch = va_arg(args, int);
          env_pc(ch);
          continue;
        }
        case 'd':
        case 'i': {
          int num = va_arg(args, int);
          env_pn(num);
          continue;
        }
        case 'f':
        case 'F': {
          double numf = va_arg(args, double);
          env_pn(numf);
          continue;
        }
      }
    }

    env_pc(fmt[i]);
  }

  va_end(args);
}
