#include "functions.h"

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

extern struct timespec start;
extern struct timespec end;
extern float time_since_start;
extern float p_x, p_y, v_x, v_y, acc_x, acc_y;
extern int counter;
extern FILE* file;
extern timer_t timer_id;
extern struct itimerspec timer_params;
extern struct sigaction action;
extern struct sigaction action_timer;

/// @brief checks whether a file exists
/// @return indication of existance
int FileExists() {
  // try to open file and return whether it was successfull
  FILE* test_file;
  if ((test_file = fopen("imu_data.txt", "r"))) {
    fclose(test_file);
    return 1;
  }
  return 0;
}

/// @brief ensures the data file is closed upon termination
/// @param signum signal received
void DriverSignalHandler(int signum) {
  // on termination closes the imu_data file before exiting
  if (signum == SIGTERM) {
    fclose(file);
    char buffer[100] = "Closing imu_handler.\n";
    write(1, buffer, strlen(buffer));
    exit(0);
  }
}

/// @brief handles timer triggers, adds new line of data to the data file
/// @param signum signal received
void TimerSignalHandler(int signum) {
  // on alarm
  if (signum == SIGALRM) {
    clock_gettime(CLOCK_REALTIME, &end);

    // get time but dont update time_since_start yet
    float curr_time =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;
    // us current time and previous time to calculate change in time
    float dt = curr_time - time_since_start;
    // update vel/pos
    v_x += (acc_x * dt);
    v_y += (acc_y * dt);
    p_x += (v_x * dt);
    p_y += (v_y * dt);

    // update time
    time_since_start = curr_time;

    char buffer[100];
    snprintf(buffer, sizeof(buffer), "imu_handler %d is writing. Time: %.2f\n",
             getpid(), time_since_start);
    if (!(counter % 10)) write(1, buffer, strlen(buffer));

    char f_buf[100];
    snprintf(f_buf, sizeof(f_buf),
             "%.2f , %.4f , %.4f , %.4f , %.4f , %.4f , %.4f\n",
             time_since_start, p_x, p_y, v_x, v_y, acc_x, acc_y);

    // Write new line of data to the imu_data
    fwrite(f_buf, 1, strlen(f_buf), file);
    // force it to finish writing before quiting
    fflush(file);

    counter++;  // used to occasionally print
    return;
  }
}

/// @brief timer creation, but separating alarm and term signal into 2 handlers
void SetUpTimers() {
  timer_create(CLOCK_REALTIME, NULL, &timer_id);

  action.sa_handler = DriverSignalHandler;
  action.sa_flags = 0;

  sigaction(SIGTERM, &action, NULL);

  action_timer.sa_handler = TimerSignalHandler;
  action_timer.sa_flags = 0;
  sigaction(SIGALRM, &action_timer, NULL);

  int period_ms = 200;
  timer_params.it_value.tv_sec = 0;
  timer_params.it_value.tv_nsec = period_ms * 1E6;
  timer_params.it_interval.tv_sec = 0;
  timer_params.it_interval.tv_nsec = period_ms * 1E6;

  return;
}

/// @brief update current data based on last line saved in file
void UpdateCurrent() {
  // open file and find the last line
  FILE* latest_file;
  latest_file = fopen("imu_data.txt", "r");
  char line[100];
  char last_line[100] = "";

  if (latest_file == NULL) {
    perror("Error opening file.\n");
    exit(1);
  }
  // find last line
  while (fgets(line, sizeof(line), latest_file) != NULL) {
    strcpy(last_line, line);
  }
  fclose(latest_file);

  // split it in accordance to the line format and save the state
  if (sscanf(last_line, "%f , %f , %f , %f , %f , %f , %f", &time_since_start,
             &p_x, &p_y, &v_x, &v_y, &acc_x, &acc_y) == 7) {
    // offset the clock
    start.tv_sec -= (int)time_since_start;
    start.tv_nsec -= (time_since_start - (int)time_since_start) * 1E9;

    printf("Last entry time stamp: %.2f\n", time_since_start);

  } else {
    printf("Error: Could not parse float values from the last line.\n");
    exit(1);
  }

  return;
}