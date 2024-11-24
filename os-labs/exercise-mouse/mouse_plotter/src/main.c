// PLOTTER
#include <curses.h>
#include <pthread.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"

#define WINDOW_WIDTH 2560
#define WINDOW_HEIGHT 1600
#define TERM_WIDTH 100
#define TERM_HEIGHT 25

// reading flag
int read_coords_now = 0;

// binary file in exercise-mouse/mouse_saver/src/mouse_data.dat
// hard link in exercise-mouse/mouse_plotter/build/mouse_data.dat
char *bin_file_path = "mouse_data.dat";
FILE *bin_file;

// coords array
float latest_coords[2] = {TERM_WIDTH / 2, TERM_HEIGHT / 2};

float last_5_coords_array[5][2] = {{TERM_WIDTH / 2, TERM_HEIGHT / 2},
                                   {TERM_WIDTH / 2, TERM_HEIGHT / 2},
                                   {TERM_WIDTH / 2, TERM_HEIGHT / 2},
                                   {TERM_WIDTH / 2, TERM_HEIGHT / 2},
                                   {TERM_WIDTH / 2, TERM_HEIGHT / 2}};

int main() {
  // sets up timer to read from binary file every 10ms
  // and the int sig handler
  SetUpTimers();

  pthread_t binary_file_reader_thread;

  pthread_create(&binary_file_reader_thread, NULL, BinaryFileReader, NULL);

  // initialise ncurses
  initscr();
  noecho();
  curs_set(0);

  while (1) {
    clear();

    // plot the last 4 coords if they are not the same
    // 0 is the same as lastest coord, hence we start at 1
    for (int i = 1; i < 5; i++) {
      if (last_5_coords_array[i] != last_5_coords_array[i - 1]) {
        mvprintw((int)last_5_coords_array[i][1], (int)last_5_coords_array[i][0],
                 "'");
      }
    }
    mvprintw((int)last_5_coords_array[0][1], (int)last_5_coords_array[0][0],
             "*");
    usleep(10000);
    refresh();
    usleep(10000);
  }

  pthread_join(binary_file_reader_thread, NULL);
  getch();
  endwin();
}

// END OF PLOTTER
