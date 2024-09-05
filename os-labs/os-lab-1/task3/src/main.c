#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"
#include "check_hand.h"
#include "fill_deck.h"
#include "fill_hand.h"

int main() {
  struct Card deck[52];
  fill_deck(deck);

  struct Card hand[5];

  fill_hand(deck, hand);

  check_hand(hand);

  return 0;
}
