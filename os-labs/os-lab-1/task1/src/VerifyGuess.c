#include "VerifyGuess.h"

#include <stdio.h>

int VerifyGuess(int target, int guess) {
  int result = target - guess;

  if (result == 0) {
    return 0;
  } else {
    int size = sizeof(result) * 8 - 1;

    int sign = result >> size;
    if (sign == 0) {
      return 1;
    } else {
      return -1;
    }
  }
}