#include "check_hand.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
  int int_a = *((int *)a);
  int int_b = *((int *)b);

  // an easy expression for comparing
  return (int_a > int_b) - (int_a < int_b);
}
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;

    // Find the minimum element in the remaining
    // unsorted array
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    // Swap the found minimum element with the first
    // element
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

struct CardCounter {
  int hearts;
  int diamonds;
  int clubs;
  int spades;
  int twos;
  int threes;
  int fours;
  int fives;
  int sixs;
  int sevens;
  int eights;
  int nines;
  int ts;
  int js;
  int qs;
  int ks;
  int as;
};

void check_hand(struct Card *hand) {
  printf("Hand: ");

  for (int i = 0; i < 5; i++) {
    printf("%c%c | ", hand[i].value, hand[i].suit);
  }

  struct CardCounter c = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (int i = 0; i < 5; i++) {
    if (hand[i].suit == 'H') {
      c.hearts++;
    } else if (hand[i].suit == 'D') {
      c.diamonds++;
    } else if (hand[i].suit == 'C') {
      c.clubs++;
    } else if (hand[i].suit == 'S') {
      c.spades++;
    }
    if (hand[i].value == '2') {
      c.twos++;
    } else if (hand[i].value == '3') {
      c.threes++;
    } else if (hand[i].value == '4') {
      c.fours++;
    } else if (hand[i].value == '5') {
      c.fives++;
    } else if (hand[i].value == '6') {
      c.sixs++;
    } else if (hand[i].value == '7') {
      c.sevens++;
    } else if (hand[i].value == '8') {
      c.eights++;
    } else if (hand[i].value == '9') {
      c.nines++;
    } else if (hand[i].value == 'T') {
      c.ts++;
    } else if (hand[i].value == 'J') {
      c.js++;
    } else if (hand[i].value == 'Q') {
      c.qs++;
    } else if (hand[i].value == 'K') {
      c.ks++;
    } else if (hand[i].value == 'A') {
      c.as++;
    }
  }

  int *ptr = (int *)&c;
  int size = sizeof(struct CardCounter) / sizeof(int);

  for (int i = 0; i < 4; i++) {
    if (ptr[i] == 5) {
      printf("Flush!");
      return;
    }
  }

  int pairs = 0;
  int threeofkind = 0;
  int fourofkind = 0;

  for (int i = 4; i < size; i++) {
    if (ptr[i] == 2) {
      pairs++;
    };
    if (ptr[i] == 3) {
      threeofkind++;
    };
    if (ptr[i] == 4) {
      fourofkind++;
    };
  }

  if (fourofkind) {
    printf("Four of kind!");
    return;
  }
  if (threeofkind) {
    printf("Three of kind!");
    return;
  }
  if (pairs == 2) {
    printf("Two pairs!");
    return;
  }
  if (pairs == 1) {
    printf("Pair!");
    return;
  }

  int vals[5];

  for (int i = 0; i < 5; i++) {
    if (hand[i].value == 'T') {
      vals[i] = 10;
    } else if (hand[i].value == 'J') {
      vals[i] = 11;
    } else if (hand[i].value == 'Q') {
      vals[i] = 12;
    } else if (hand[i].value == 'K') {
      vals[i] = 13;
    } else if (hand[i].value == 'A') {
      vals[i] = 14;
    } else {
      // int v = atoi(hand[i].value);

      int v = hand[i].value - '0';
      vals[i] = v;
    }
  }
  selectionSort(vals, 5);

  int straight = 1;

  if (vals[4] == 14 && vals[3] != 13) {
    vals[4] = vals[3];
    vals[3] = vals[2];
    vals[2] = vals[1];
    vals[1] = vals[0];
    vals[0] = 1;
  };

  if (vals[0] == 1 && vals[1] != 2) {
    straight = 0;
  };

  int min = vals[0];
  int max = vals[4];
  int range = max - min;

  if (range == 4) {
    for (int i = 1; i < 4; i++) {
      if (!(min < vals[i] < max)) {
        straight = 0;
      }
    }
  } else {
    straight = 0;
  }

  if (straight) {
    printf("Straight!");
    return;
  }

  printf("No combination.");
}
