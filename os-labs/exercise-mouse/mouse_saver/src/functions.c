#include "functions.h"

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

#define WINDOW_WIDTH 2560
#define WINDOW_HEIGHT 1600
#define TERM_WIDTH 100
#define TERM_HEIGHT 25

extern char* mouse_file_path;
extern char* bin_file_path;
extern FILE* mouse_file;
extern FILE* bin_file;
extern int break_loop;
extern int curr_pos[2];

/// @brief thread that handles reading the mouse deltas
/// reads a delta, converts it to abs pos
/// takes the abs pos and converts it to term coords
/// sends the term coords to the writer thread via msg queue
void* MouseReaderThread() {
  mouse_file = fopen(mouse_file_path, "rb");
  bin_file = fopen(bin_file_path, "wb");
  if (mouse_file == NULL) {
    perror("Error opening mouse device");
    exit(1);
  }

  // capture mouse deltas and send them to the writer thread
  while (!break_loop) {
    // read deltas
    unsigned char data[3];  // Raw data from /dev/input/mice
    size_t bytes_read = fread(data, sizeof(unsigned char), 3, mouse_file);
    if (bytes_read < 3) {
      perror("Error reading from mouse device");
      break;
    }

    // Extract x and y deltas (data[1] and data[2] are the x and y deltas)
    int8_t x_delta = (int8_t)data[1];
    int8_t y_delta = (int8_t)data[2];

    // convert deltas to abs pos

    AddDeltasToAbsPos(x_delta, y_delta);

    float term_coords[2];
    // convert abs pos to term coords
    AbsPosToTermCoords(&term_coords);
    printf("%f, %f\n", term_coords[0], term_coords[1]);

    // transform term coords to int format
    int coords_in_int_format = ConvertCoordsToIntFormat(term_coords);

    printf("%d\n", coords_in_int_format);

    // Write the integer directly to the binary file
    fwrite(&coords_in_int_format, sizeof(int), 1, bin_file);
    fflush(bin_file);
  }
  return NULL;
}

/// @brief
/// @param x_delta
/// @param y_delta
/// @return
void AddDeltasToAbsPos(int8_t x_delta, int8_t y_delta) {
  // add delta positions to absolute positions

  curr_pos[0] += x_delta;
  curr_pos[1] -= y_delta;
  // Ensure the mouse position stays within the screen boundaries
  curr_pos[0] = (curr_pos[0] < 0) ? 0 : curr_pos[0];
  curr_pos[0] = (curr_pos[0] > WINDOW_WIDTH) ? WINDOW_WIDTH : curr_pos[0];
  curr_pos[1] = (curr_pos[1] < 0) ? 0 : curr_pos[1];
  curr_pos[1] = (curr_pos[1] > WINDOW_HEIGHT) ? WINDOW_HEIGHT : curr_pos[1];
  printf("pos: %d, %d\n", curr_pos[0], curr_pos[1]);
}

/// @brief Convert pixel coordinates to terminal coordinates
/// assuming 100x25 terminal size
/// @param x
void AbsPosToTermCoords(float* term_coords) {
  float x_ratio = (float)curr_pos[0] / WINDOW_WIDTH;
  float y_ratio = (float)curr_pos[1] / WINDOW_HEIGHT;

  term_coords[0] = x_ratio * TERM_WIDTH;
  term_coords[1] = y_ratio * TERM_HEIGHT;

  // Ensure the term coordinates are within terminal bounds
  if (term_coords[0] < 0) term_coords[0] = 0;
  if (term_coords[0] >= TERM_WIDTH) term_coords[0] = TERM_WIDTH - 1;
  if (term_coords[1] < 0) term_coords[1] = 0;
  if (term_coords[1] >= TERM_HEIGHT) term_coords[1] = TERM_HEIGHT - 1;
}

/// @brief takes a coordinate and converts it to int format
/// @param x
/// @param y
/// @return the int format
int ConvertCoordsToIntFormat(float* term_coords) {
  // Combine two integers into a single integer for compact storage
  int x_int = (int)round(term_coords[0]);
  int y_int = (int)round(term_coords[1]);
  return (x_int << 16) | (y_int & 0xFFFF);  // Pack x and y into a single int
}

/// @brief flushes, closes files and kills the process
/// @param signum
void signal_handler(int signum) {
  if (signum == SIGINT) {
    fflush(bin_file);

    bin_file = fclose(bin_file);
    break_loop = 0;
    kill(getpid(), SIGKILL);
  }
}