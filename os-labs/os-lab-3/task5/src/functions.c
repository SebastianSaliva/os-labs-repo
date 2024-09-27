#include "functions.h"

#include <curses.h> /* ncurses.h incluye stdio.h */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_BALLS 10

extern int counter_val;

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

extern int row;
extern int col;
extern int direction;
extern BallData balls_arr[MAX_BALLS];
extern int ball_count;
extern int balls_to_add;

int can_add_ball = 1;
void* UpdateBallPos(void* param) {
  // int* ptr_init_c = (int*)param;

  // for (int i = *ptr_init_c; i < 35; i++) {
  //   printf("%d\n", i);
  //   usleep(500000);
  // }

  while (!break_loop) {
    int i = 0;
    for (i; i < ball_count; i++) {
      BallData* ball = &balls_arr[i];
      ball->dx;
      ball->dy;
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
    }
    while (balls_to_add && can_add_ball) {
      if (ball_count < MAX_BALLS) {
        int x = 10;
        int y = 20;
        BallData new_ball = {x, y, 1, 1};
        balls_arr[i] = new_ball;

        balls_to_add -= 1;
        ball_count++;
        i++;
      } else {
        can_add_ball = 0;
      }
    }
    usleep(100000); /* Duerme por 100ms */
  }

  // tdata->result = result;
  // pthread_exit(NULL);
}

#define ENTER_ASCII 13
#define SPACE_ASCII 32

extern int break_loop;
void* fetch_key_strokes() {
  initscr();
  keypad(stdscr, TRUE);
  noecho();

  srand(time(NULL));  // Initialization, should only be called once.
  int r = rand();     // Returns a pseudo-random integer between 0 and RAND_MAX.
  int key_stroke;
  while (!break_loop) {
    key_stroke = getch();
    refresh();
    switch (key_stroke) {
      case 'c':
        for (int i = 0; i < ball_count; i++) {
          balls_arr[i].dx *= -1;
          balls_arr[i].dy *= -1;
        }
        break;

      case SPACE_ASCII:
        if (can_add_ball) balls_to_add++;
        break;
      case ENTER_ASCII:

        break_loop = 1;
        break;
    }
  }
}