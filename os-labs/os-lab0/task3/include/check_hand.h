#ifndef CHECK_HAND_H
#define CHECK_HAND_H

#include "Card.h"

void selectionSort(int arr[], int n);

int compare(const void *a, const void *b);

void check_hand(struct Card *hand);

#endif  // CHECK_HAND_H