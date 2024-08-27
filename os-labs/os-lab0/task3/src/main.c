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

  for (int i = 0; i < 52; i++) {
    printf("%c%c ", deck[i].value, deck[i].suit);
    if ((i + 1) % 13 == 0) printf("\n");
  }
  struct Card hand[5];

  fill_hand(deck, hand);

  for (int i = 0; i < 5; i++) {
    printf("%c%c/ ", hand[i].value, hand[i].suit);
  }

  return 0;
}
