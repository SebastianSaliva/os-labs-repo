#include <stdio.h>

#include "GenerateRandNumber.h"
#include "GetUserGuess.h"
#include "VerifyGuess.h"

int main() {
  int playing = 1;

  int maxNum = 100;

  int tryCount = 0;

  int target = GenerateRandNumber(maxNum);

  printf("Welcome! Guess a number between 1 and %d!\n", maxNum);

  while (playing) {
    int guess = GetUserGuess();
    tryCount++;

    int result = VerifyGuess(target, guess);

    if (result == 0) {
      printf("Guessed correctly! Tries: %d \n", tryCount);
      playing = 0;
    } else if (result == 1) {
      printf("Wrong guess, guess higher!\n");
    } else if (result == -1) {
      printf("Wrong guess, guess lower!\n");
    }
  }
  return 0;
}
