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

int break_loop;
int counter_val;
int row, col;
int direction;
int ball_count, balls_to_add;
BallData balls_arr[MAX_BALLS];
int ball_id_arr[MAX_BALLS];
pthread_t* threads_arr[MAX_BALLS];

int main() {
  direction = 1;
  break_loop = 0;
  counter_val = 0;
  balls_to_add = 0;
  ball_count = 0;
  getmaxyx(stdscr, row, col);

  // fill ids and threads array
  for (int i = 0; i < MAX_BALLS; i++) {
    ball_id_arr[i] = i;
    pthread_t p_ball_handler;
    threads_arr[i] = &p_ball_handler;
  }

  pthread_t p_update_counter;
  pthread_t p_fetch_key_strokes;

  initscr();
  curs_set(0);
  pthread_create(&p_fetch_key_strokes, NULL, FetchKeyStrokes, NULL);
  pthread_create(&p_update_counter, NULL, UpdateCounter, NULL);

  AddBall();

  while (!break_loop) {
    clear();
    getmaxyx(stdscr, row, col);
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
