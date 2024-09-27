#include "functions.h"

#include <curses.h> /* ncurses.h incluye stdio.h */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_BALLS 20

extern int counter_val;
extern int break_loop;
extern pthread_t* threads_arr[MAX_BALLS];
extern int ball_id_arr[MAX_BALLS];
void* UpdateCounter() {
  while (!break_loop) {
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
  int* ball_id = (int*)param;
  int* x = &balls_arr[*ball_id].x;
  int* y = &balls_arr[*ball_id].y;
  int* dy = &balls_arr[*ball_id].dy;
  int* dx = &balls_arr[*ball_id].dx;

  while (!break_loop) {
    *x += *dx;
    *y += *dy;
    if (*x >= col - 1) *dx = -1;

    if (*y >= row - 1) *dy = -1;

    if (*x <= 1) *dx = 1;

    if (*y <= 1) *dy = 1;

    usleep(100000); /* Duerme por 100ms */
  }
}

#define ENTER_ASCII 13
#define SPACE_ASCII 32

void* fetch_key_strokes() {
  keypad(stdscr, TRUE);
  noecho();

  srand(time(NULL));

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
        if (can_add_ball) {
          int ball_id = 0;
          ball_id += ball_count;

          int x = rand() % (col - 1) + 1;
          int y = rand() % (row - 1) + 1;

          int dx = 1;
          int dy = 1;
          uint8_t s = rand() % 4;
          if (s & 1) dx *= -1;
          s = s >> 1;
          if (s & 1) dy *= -1;

          BallData new_ball = {x, y, dx, dy};
          balls_arr[ball_id] = new_ball;

          pthread_create(threads_arr[ball_id], NULL, UpdateBallPos,
                         (void*)&ball_id_arr[ball_id]);
          ball_count++;
          if (ball_count >= MAX_BALLS) can_add_ball = 0;
        }
        break;
      case ENTER_ASCII:

        break_loop = 1;
        break;
    }
  }
}