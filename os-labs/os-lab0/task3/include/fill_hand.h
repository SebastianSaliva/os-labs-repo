#ifndef FILL_HAND_H
#define FILL_HAND_H
#include <stdbool.h>

#include "Card.h"

void fill_hand(struct Card *deck, struct Card *hand);
bool isIntInArray(int arr[], int target);
int GenerateRandNumber(int max);

#endif  // FILL_HAND_H