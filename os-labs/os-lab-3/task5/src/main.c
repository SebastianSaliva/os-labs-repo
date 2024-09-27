#include <curses.h> /* ncurses.h incluye stdio.h */
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "functions.h"

#define MAX_BALLS 20

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
} BallData;

int counter_val;
int row, col;
int direction;
BallData balls_arr[MAX_BALLS];
int ball_count;
int balls_to_add;
int break_loop;
pthread_t* threads_arr[MAX_BALLS];
int ball_id_arr[MAX_BALLS];
int main() {
  for (int i = 0; i < MAX_BALLS; i++) {
    ball_id_arr[i] = i;
    pthread_t p_ball_handler;
    threads_arr[i] = &p_ball_handler;
  }
  counter_val = 0;
  direction = 1;
  ball_count = 1;
  balls_to_add = 0;
  break_loop = 0;

  BallData ball = {10, 20, 1, 1};
  balls_arr[0] = ball;

  getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */

  pthread_t p_update_counter;
  pthread_t p_fetch_key_strokes;

  initscr();
  curs_set(0);
  pthread_create(&p_fetch_key_strokes, NULL, fetch_key_strokes, NULL);
  pthread_create(&p_update_counter, NULL, UpdateCounter, NULL);
  pthread_create(threads_arr[0], NULL, UpdateBallPos, (void*)&ball_id_arr[0]);
  pthread_t id1, id2;

  while (!break_loop) {
    clear();
    getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */
    mvprintw(0, 0, "%d", counter_val);

    for (int i = 0; i < ball_count; i++) {
      mvprintw(balls_arr[i].y, balls_arr[i].x, "o");
    }
    refresh();
    usleep(100000);
  }

  pthread_join(p_update_counter, NULL);
  pthread_join(p_fetch_key_strokes, NULL);

  getch();
  endwin();

  return 0;
}
