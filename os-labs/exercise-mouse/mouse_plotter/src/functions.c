#include "functions.h"

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

#define WINDOW_WIDTH 2560
#define WINDOW_HEIGHT 1600
#define TERM_WIDTH 100
#define TERM_HEIGHT 25

// reading flag
extern int read_coords_now;

// binary file in exercise-mouse/mouse_saver/src/mouse_data.dat
// hard link in exercise-mouse/mouse_plotter/build/mouse_data.dat
extern char* bin_file_path;
extern FILE* bin_file;

// coords
extern float latest_coords[2];
extern float prev_coords[2];

extern float last_5_coords_array[5][2];

/// @brief signal handler, sets flag to 1 to
/// let reading thread know it should read the next coord set
/// @param signum
void ReadCoordSet(int signum) {
  if (signum == SIGUSR1) {
    // printf("Reading coord set from bin file\n");
    read_coords_now = 1;
  }
}

void ShiftCoordsArray() {
  // Shift the array elements to the right
  for (int i = 4; i > 0; i--) {
    last_5_coords_array[i][0] = last_5_coords_array[i - 1][0];
    last_5_coords_array[i][1] = last_5_coords_array[i - 1][1];
  }
}

/// @brief thread that handles reading coords from binary file
void* BinaryFileReader() {
  bin_file = fopen(bin_file_path, "rb");
  if (bin_file == NULL) {
    perror("Error opening file");
    return 1;
  }

  while (1) {
    if (read_coords_now) {
      float x, y;
      int x_y_line = 0;

      // read line from bin file that is formated as int
      x_y_line = ReadIntFromBinFile();
      // parse line to get x and y
      x = x_y_line >> 16;
      y = x_y_line & 0xFFFF;
      // printf("x: %f, y: %f\n", x, y);

      // shift last_5_coords_array to the left

      ShiftCoordsArray();
      latest_coords[0] = x;
      latest_coords[1] = y;
      // replace 0th element with latest coords
      last_5_coords_array[0][0] = latest_coords[0];
      last_5_coords_array[0][1] = latest_coords[1];

      read_coords_now = 0;
    }
  }
}

/// @brief seek the latest int written to the bin file
/// @return latest int writtern to file
int ReadIntFromBinFile() {
  int coords_in_int_format;

  if (fseek(bin_file, -sizeof(int), SEEK_END) != 0) {
    perror("Error seeking in file");
    exit(EXIT_FAILURE);
  }

  // Read an integer from the binary file
  size_t result = fread(&coords_in_int_format, sizeof(int), 1, bin_file);

  if (result != 1) {
    if (feof(bin_file)) {
      // End of file reached; wait for new data
      clearerr(bin_file);  // Clear EOF flag

      return -1;  // Indicate no data read
    } else {
      perror("Error reading from file");
      exit(EXIT_FAILURE);
    }
  }

  return coords_in_int_format;
}

/// @brief set up timer and interrupt sig handler
void SetUpTimers() {
  // set up action handlers
  struct sigaction action;
  action.sa_handler = IntSigHandler;
  action.sa_flags = 0;
  sigaction(SIGINT, &action, NULL);

  // 2. Custom Timer
  timer_t timer_id;
  struct itimerspec timer_params;

  // change timer signal and setup timer
  int signum = SIGUSR1;
  struct sigevent event;
  event.sigev_notify = SIGEV_SIGNAL;
  event.sigev_signo = signum;
  timer_create(CLOCK_REALTIME, &event, &timer_id);

  struct sigaction action_timer;
  action_timer.sa_handler = ReadCoordSet;
  action_timer.sa_flags = 0;
  sigaction(SIGUSR1, &action_timer, NULL);

  int period_ms = 10;
  timer_params.it_value.tv_sec = 0;
  timer_params.it_value.tv_nsec = period_ms * 1E6;
  timer_params.it_interval.tv_sec = 0;
  timer_params.it_interval.tv_nsec = period_ms * 1E6;
  // start timer
  timer_settime(timer_id, 0, &timer_params, NULL);
}

/// @brief handles closing file and exiting program
/// @param signum
void IntSigHandler(int signum) {
  if (signum == SIGINT) {
    fclose(bin_file);
    kill(getpid(), SIGKILL);
  }
}
