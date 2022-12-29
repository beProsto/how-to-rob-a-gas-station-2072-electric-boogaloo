#include <env/memory.h>
#include <env/print.h>

void
main()
{
  const char* string1 = "Hello, Marmeladka! What's Up at yours bro?";

  int numberToReturn = 4 * 4;

  printf(
    "%s The number's %d, and char's %c\nAAAAAA THERE ARE DECIMALS ALSO %f!!!\n",
    string1,
    numberToReturn,
    'a',
    2.5);
}
