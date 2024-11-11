#include <curses.h> /* ncurses.h incluye stdio.h */
#include <curses.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"

#define MAX_BALLS 20

#define ENTER_ASCII 13
#define SPACE_ASCII 32

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
} BallData;

extern int counter_val;
extern int break_loop;
extern pthread_t* threads_arr[MAX_BALLS];
extern BallData balls_arr[MAX_BALLS];
extern int ball_id_arr[MAX_BALLS];
extern int row;
extern int col;
extern int direction;
extern int ball_count;
extern int balls_to_add;
int can_add_ball = 1;

/**
 * @brief increments counter value by 1 every second
 *
 */
void* UpdateCounter() {
  while (!break_loop) {
    counter_val++;
    sleep(1);
  }
}

/**
 * @brief thread that updates the position of a target ball and wait 100ms
 *
 * @param[in] target_id index of the ball the thread will update
 *
 */
void* UpdateBallPos(void* target_id) {
  int* ball_id = (int*)target_id;

  // get the pointers of the data values of the ball this thread should modify
  int* x = &balls_arr[*ball_id].x;
  int* y = &balls_arr[*ball_id].y;
  int* dy = &balls_arr[*ball_id].dy;
  int* dx = &balls_arr[*ball_id].dx;

  while (!break_loop) {
    // update coords of target ball and check boundries
    *x += *dx;
    *y += *dy;
    if (*x >= col - 1) *dx = -1;
    if (*y >= row - 1) *dy = -1;
    if (*x <= 1) *dx = 1;
    if (*y <= 1) *dy = 1;

    usleep(100000);
  }
}

/**
 * @brief detects key presses, and does corresponding action
 *
 * if c is pressed, the direction of all balls is changed.
 *
 * if space is pressed, a ball is added if it can be.
 *
 * if enter is pressed break_loop is changed to true such that all threads quit
 *
 */
void* FetchKeyStrokes() {
  keypad(stdscr, TRUE);
  noecho();

  srand(time(NULL));

  int key_stroke;
  while (!break_loop) {
    key_stroke = getch();

    switch (key_stroke) {
      case 'c':
        // change direction off all balls by multiplying by -1
        for (int i = 0; i < ball_count; i++) {
          balls_arr[i].dx *= -1;
          balls_arr[i].dy *= -1;
        }
        break;

      case SPACE_ASCII:
        if (can_add_ball) AddBall();
        break;
      case ENTER_ASCII:
        break_loop = 1;
        break;
    }
  }
}

/**
 * @brief creates a new instance of a ball and adds it to the ball array
 */
void AddBall() {
  int ball_id = 0;
  ball_id += ball_count;

  // randomize initial coords / direction
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

  // to pass the ball_id we must save it to an array in order for it to
  // not get changed in subsequent calls
  pthread_create(threads_arr[ball_id], NULL, UpdateBallPos,
                 (void*)&ball_id_arr[ball_id]);
  ball_count++;
  if (ball_count >= MAX_BALLS) can_add_ball = 0;
}

int counter_val;
int row, col;

int main() {
  counter_val = 0;

  getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */

  pthread_t p_update_ball;
  pthread_t p_update_counter;

  pthread_create(&p_update_counter, NULL, UpdateCounter, NULL);

  initscr();

  curs_set(0);

  BallData ball;
  ball.x = 10;
  ball.y = 20;
  ball.dx = 1;
  ball.dy = 1;

  pthread_create(&p_update_ball, NULL, UpdateBallPos, (void*)&ball);

  while (1) {
    clear();
    getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */
    mvprintw(0, 0, "%d", counter_val);
    mvprintw(ball.y, ball.x, "o");
    refresh();
    usleep(100000);
  }

  pthread_join(p_update_ball, NULL);
  pthread_join(p_update_counter, NULL);

  getch();
  endwin();

  return 0;
}
