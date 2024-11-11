#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>  // for setpriority
#include <sys/wait.h>
#include <unistd.h>

#include "functions.h"

// IMPORTANT NOTE: YOU MAY NEED TO RUN CMAKE .. TWICE FOR IT TO DETECT c99, IDKY

#define NUM_CHILDREN 3

/// @brief Measure the
/// @param argc
/// @param argv the values of the priorities the 3 Processes are to have eg.
/// ./task -10 0 10, P1 takes prio -10, P2 0, P3 10.
/// 0 0 0 is used if no args are provided.

int main(int argc, char* argv[]) {
  int use_basecase = 0;
  if (argc == 1) {
    printf("No arguments provided.\n");
    printf("Using Equivalent to: ./<task> 0 0 0\n");
    use_basecase = 1;
  }

  int priorities[NUM_CHILDREN] = {};

  if (use_basecase) {
    priorities[0] = 0;
    priorities[1] = 0;
    priorities[2] = 0;
  } else {
    if (argc < 4 || 5 <= argc) {
      printf("Invalid amount of args, please do ./<task> 0 -10 10\n");
    } else {
      for (int i = 0; i < NUM_CHILDREN; i++) {
        // get priorities from arguments, check whether its valid and in range
        priorities[i] = atoi(argv[i + 1]);
        if (!priorities[i] && priorities[i] != 0) {
          perror("Invalid priority in arguments\n");
          exit(1);
        }
        if (!(-20 <= priorities[i] && priorities[i] <= 20)) {
          perror("Priority argument out of range\n");
          exit(1);
        }
      }
    }
  }

  // set starting time in seconds
  struct timeval tv;
  gettimeofday(&tv, NULL);  // Get current time
  double start_time_secs = ((double)tv.tv_sec + (double)tv.tv_usec / 1000000);

  pid_t pids[NUM_CHILDREN];

  // Create multiple CPU-bound processes with different priorities
  for (int i = 0; i < NUM_CHILDREN; i++) {
    pids[i] = fork();
    if (pids[i] < 0) {
      perror("fork");
      exit(1);
    }

    if (pids[i] == 0) {
      // In child process
      printf("P:%d (pid: %d) initializes with priority %d\n", i + 1, getpid(),
             getpriority(PRIO_PROCESS, getpid()));

      // Set the priority of this process
      if (setpriority(PRIO_PROCESS, getpid(), priorities[i]) < 0) {
        perror("setpriority");
        exit(1);
      }

      printf("P:%d (pid: %d) now has priority %d\n", i + 1, getpid(),
             priorities[i]);
      // Start the CPU-bound task
      CpuBoundTask(i + 1, priorities[i], start_time_secs);
      exit(0);  // Shouldn't reach here
    }
  }

  // Parent process: wait for all child processes
  for (int i = 0; i < NUM_CHILDREN; i++) {
    wait(NULL);  // Waiting for child processes (will block)
  }

  return 0;
}