#include "GenerateRandNumber.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GenerateRandNumber(int max) {
  srand(time(NULL));
  int r = rand() % max + 1;

  return r;
}