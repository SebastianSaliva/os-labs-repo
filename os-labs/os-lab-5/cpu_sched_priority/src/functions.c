#include "functions.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>  // for setpriority
#include <sys/wait.h>
#include <unistd.h>

/// @brief a function called by a child process to simulate a cpu-bound-task
/// @param id the relative identifier of the process, eg 1, 2, 3, not the pid
/// @param prio the priority the process calling this function was set to,
/// passed as arg to print it
/// @param start_time_secs the time in seconds at which the parent process
/// started, used to measure delta
void CpuBoundTask(int id, int prio, double start_time_secs) {
  printf("P:%d (pid: %d) started running cpu-bound-task.\n", id, getpid());

  struct timeval tv;

  int count = 0;
  while (count < 30) {
    for (volatile long i = 0; i < 1000000000; i++);  // CPU-bound work
    count++;

    // Optional Print, ommitted since it might not purely use the cpu
    // printf("P:%d (pid: %d) runs: %d / 30\n", id, getpid(), count);
  }

  // convert u secs to secs and add them to tv_sec to calculate delta from start
  gettimeofday(&tv, NULL);
  double time_delta =
      ((double)tv.tv_sec + (double)tv.tv_usec / 1000000) - start_time_secs;

  printf("P:%d (pid: %d) (priority: %d) ended. Time Delta: %lf\n", id, getpid(),
         prio, time_delta);
}