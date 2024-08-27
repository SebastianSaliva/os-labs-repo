#include "GetUserGuess.h"

#include <stdio.h>

int GetUserGuess() {
  int input;
  printf("Enter Your Guess: ");
  scanf("%d", &input);
  return input;
}
