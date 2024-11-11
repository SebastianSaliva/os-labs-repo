#include <curses.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"

#define ENTER_ASCII 13
#define SPACE_ASCII 32

int break_loop = 0;

void* FetchKeyStrokes() {
  // keypad(stdscr, TRUE);
  // noecho();

  // srand(time(NULL));

  int key_stroke;
  while (!break_loop) {
    key_stroke = getch();

    switch (key_stroke) {
      case 'c':
        printf("c pressed\n");
        mvprintw(0, 1, "c pressed");
        break;
      case SPACE_ASCII:

        break;
      case ENTER_ASCII:
        break_loop = 1;
        break;
    }
  }
}
int row, col = 0;
int counter_val = 0;
int main() {
  initscr();
  curs_set(0);
  getmaxyx(stdscr, row, col);

  pthread_t p_fetch_key_strokes;
  pthread_create(&p_fetch_key_strokes, NULL, FetchKeyStrokes, NULL);

  while (!break_loop) {
    clear();
    getmaxyx(stdscr, row, col);
    mvprintw(0, 0, "%d", counter_val);

    refresh();
    usleep(100000);
  }
  pthread_join(p_fetch_key_strokes, NULL);
  endwin();
  return 0;
}
