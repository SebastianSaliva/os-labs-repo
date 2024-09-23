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
int direction;
int main() {
  counter_val = 0;
  direction = 1;
  getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */

  pthread_t p_updateBallPos;
  pthread_t p_updateCounter;

  pthread_create(&p_updateCounter, NULL, UpdateCounter, NULL);
  pthread_t id1, id2;

  initscr();
  keypad(stdscr, TRUE);
  noecho();

  curs_set(0);

  int key_stroke;
  int break_loop = 0;
  while (!break_loop) {
    key_stroke = getch();
    refresh();
    switch (key_stroke) {
      case KEY_LEFT:
        /* code */
        break;
      case 'f':
        /* code */
        break;
      case ENTER_NCURSES:
        // case KEY_ENTER:
        break_loop = 1;
        break;
    }
  }

  BallData ball1;
  ball1.x = 10;
  ball1.y = 20;
  ball1.dx = 1;
  ball1.dy = 1;

  pthread_create(&p_updateBallPos, NULL, UpdateBallPos, (void*)&ball1);

  while (1) {
    clear();
    getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */
    mvprintw(0, 0, "%d", counter_val);
    mvprintw(ball1.y, ball1.x, "o");
    refresh();
    usleep(100000);
  }

  pthread_join(p_updateBallPos, NULL);
  pthread_join(p_updateCounter, NULL);

  getch();
  endwin();

  return 0;
}
