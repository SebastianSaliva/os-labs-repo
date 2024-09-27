#include <curses.h> /* ncurses.h incluye stdio.h */
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "functions.h"
typedef struct {
  int x;
  int y;
  int dx;
  int dy;
} BallData;

#define ENTER_NCURSES 10

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
