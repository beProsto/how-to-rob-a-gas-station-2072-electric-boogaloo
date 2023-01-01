#include <env/input.h>
#include <env/memory.h>
#include <env/print.h>
#include <stdbool.h>

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

struct input_t input = {};

void
loop()
{
  env_ig(&input);

  printf("Mouse is on: %d : %d\n", input.position_x, input.position_y);
  printf("Mouse delta: %d : %d\n", input.delta_x, input.delta_y);
  printf("Mouse wheel: %d : %d\n", input.scroll_x, input.scroll_y);
  printf("Mouse buttons: [%d / %d / %d | %d / %d]\n",
         input.buttons[0],
         input.buttons[1],
         input.buttons[2],
         input.buttons[3],
         input.buttons[4]);
  printf("Keyboard: W[%d] S[%d] A[%d] D[%d] Space[%d]\n",
         input.keys[87],
         input.keys[83],
         input.keys[65],
         input.keys[68],
         input.keys[32]);
}