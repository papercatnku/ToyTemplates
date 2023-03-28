#pragma once

#include "foolib.h"

struct Bar {
  int x = 3;
  float y = 2.0f;
  char z[100] = "hello";
};

void printBAR(const Bar *pBar);