#include "functions.h"

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern int counter_val;
extern int row;
extern int col;

void* UpdateCounter() {
  while (1) {
    counter_val++;
    sleep(1);
  }
}

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
} BallData;

void* UpdateBallPos(void* param) {
  BallData* ball = (BallData*)param;

  while (1) {
    ball->x += ball->dx;
    ball->y += ball->dy;
    if (ball->x >= col - 1) {
      ball->dx = -1;
    }
    if (ball->y >= row - 1) {
      ball->dy = -1;
    }
    if (ball->x <= 1) {
      ball->dx = 1;
    }
    if (ball->y <= 1) {
      ball->dy = 1;
    }

    usleep(100000); /* Duerme por 100ms */
  }
}