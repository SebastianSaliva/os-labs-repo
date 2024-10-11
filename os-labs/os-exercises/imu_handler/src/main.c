#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"

struct timespec start;
struct timespec end;

float time_since_start = 0;
float p_x = 20;
float p_y = 10;
float v_x = 0;
float v_y = 0;
float acc_x = 0.15;
float acc_y = 0.06;

int counter = 0;
FILE* file;
timer_t timer_id;

struct itimerspec timer_params;
struct sigaction action;
struct sigaction action_timer;
int main() {
  printf("imu_handler ");
  clock_gettime(CLOCK_REALTIME, &start);
  SetUpTimers();

  // check if imu_data exists
  if (FileExists()) {
    printf("restarted...\n");
    // split the last line of the file to get the latest data
    UpdateCurrent();
    // open in append mode
    file = fopen("imu_data.txt", "a");

  } else {
    printf("started!\n");
    // if the file doesn't exist, create it and write the initial state
    file = fopen("imu_data.txt", "w");
    fprintf(file, "%.2f , %.4f , %.4f , %.4f , %.4f , %.4f , %.4f\n",
            time_since_start, p_x, p_y, v_x, v_y, acc_x, acc_y);
  }

  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // start timer
  timer_settime(timer_id, 0, &timer_params, NULL);

  while (1) {
    usleep(100000);
  }
  fclose(file);
  return 0;
}
