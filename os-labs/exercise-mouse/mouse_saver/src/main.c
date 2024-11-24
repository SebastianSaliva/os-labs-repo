
#include <math.h>
#include <pthread.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"

#define WINDOW_WIDTH 2560
#define WINDOW_HEIGHT 1600
#define TERM_WIDTH 100
#define TERM_HEIGHT 25

char* mouse_file_path = "/dev/input/mice";
char* bin_file_path = "../src/mouse_data.dat";
FILE* mouse_file;
FILE* bin_file;
int break_loop = 0;

int curr_pos[2] = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

int main() {
  struct sigaction sa;
  sa.sa_handler = signal_handler;
  sigaction(SIGINT, &sa, NULL);

  pthread_t p_reader_thread;

  pthread_create(&p_reader_thread, NULL, MouseReaderThread, NULL);

  pthread_join(p_reader_thread, NULL);

  return 0;
}
