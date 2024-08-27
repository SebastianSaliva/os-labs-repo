#include "check_hand.h"

#include <stdio.h>

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
  char suits[] = {'H', 'D', 'C', 'S'};  // Hearts, Diamonds, Clubs, Spades
  char values[] = {'2', '3', '4', '5', '6', '7', '8',
                   '9', 'T', 'J', 'Q', 'K', 'A'};
  struct CardCounter c = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < 5; i++) {
    if (hand[i].suit == 'H') {
      c.hearts++;
    }
    if (hand[i].suit == 'D') {
      c.diamonds++;
    }
    if (hand[i].suit == 'C') {
      c.clubs++;
    }
    if (hand[i].suit == 'S') {
      c.spades++;
    }
    if (hand[i].value == '2') {
      c.twos++;
    }
    if (hand[i].value == '3') {
      c.threes++;
    }
    if (hand[i].value == '4') {
      c.fours++;
    }
    if (hand[i].value == '5') {
      c.fives++;
    }
    if (hand[i].value == '6') {
      c.sixs++;
    }
    if (hand[i].value == '7') {
      c.sevens++;
    }
    if (hand[i].value == '8') {
      c.eights++;
    }
    if (hand[i].value == '9') {
      c.nines++;
    }
    if (hand[i].value == 'T') {
      c.ts++;
    }
    if (hand[i].value == 'J') {
      c.js++;
    }
    if (hand[i].value == 'Q') {
      c.qs++;
    }
    if (hand[i].value == 'K') {
      c.ks++;
    }
    if (hand[i].value == 'A') {
      c.as++;
    }
  }

  int index = 0;
}
