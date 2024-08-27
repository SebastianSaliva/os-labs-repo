#include "fill_deck.h"

#include <stdio.h>

void fill_deck(struct Card *deck) {
  char suits[] = {'H', 'D', 'C', 'S'};  // Hearts, Diamonds, Clubs, Spades
  char values[] = {'2', '3', '4', '5', '6', '7', '8',
                   '9', 'T', 'J', 'Q', 'K', 'A'};
  int index = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      deck[index].suit = suits[i];
      deck[index].value = values[j];
      index++;
    }
  }
}
