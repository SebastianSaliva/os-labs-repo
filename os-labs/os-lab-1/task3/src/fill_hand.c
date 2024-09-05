#include "fill_hand.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"

// Function to check if an integer is in an array

int GenerateRandNumber(int max) {
  int r = rand() % max;

  return r;
}

bool isIntInArray(int arr[], int target) {
  for (int i = 0; i < 5; i++) {
    if (arr[i] == target) {
      return true;  // Target found in the array
    }
  }
  return false;  // Target not found in the array
}

void fill_hand(struct Card *deck, struct Card *hand) {
  int rnums[5];
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    int r = GenerateRandNumber(52);
    bool dup = isIntInArray(rnums, r);
    if (dup) {
      i--;
    } else {
      rnums[i] = r;
    }
  }

  for (int i = 0; i < 5; i++) {
    hand[i] = deck[rnums[i]];
  }
  printf("\n");
}
