#pragma once

#include <stdbool.h>
#include <stdint.h>

// Polling every value all at once
struct input_t
{
  int32_t position_x;
  int32_t position_y;
  int32_t delta_x;
  int32_t delta_y;
  int32_t scroll_x;
  int32_t scroll_y;
  uint32_t width;
  uint32_t height;
  bool keys[256];
  bool buttons[5];
};

// Input getter
void
env_ig(struct input_t* ptr);