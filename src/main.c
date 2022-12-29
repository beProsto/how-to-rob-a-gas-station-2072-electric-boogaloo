#include <env/print.h>

int
exported_function(int number)
{
  const char* string1 = "Hello, Marmeladka!";

  int numberToReturn = number * 4;

  printf("%s The number's %d, and char's %c\nAAAAAA PAIN %F!!!\n",
         string1,
         numberToReturn,
         'a',
         2.5);

  return numberToReturn;
}
