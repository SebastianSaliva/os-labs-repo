#include "functions.h"

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
} BallData;

extern int counter_val;
extern int row;
extern int col;
/**
 * @brief updates the value of the counter every second
 *
 */
void* UpdateCounter() {
  while (1) {
    counter_val++;
    sleep(1);
  }
}
/**
 * @brief update the coords of the ball every 100ms
 *
 * @param[in] target_ball pointer to the instance of ball to be updated
 */
void* UpdateBallPos(void* target_ball) {
  BallData* ball = (BallData*)target_ball;

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

    usleep(100000);
  }
}