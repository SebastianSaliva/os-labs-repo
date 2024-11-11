#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>  // for setpriority
#include <sys/wait.h>
#include <unistd.h>

int num_children = 0;

void cpu_bound_task(int id) {
  printf("Process %d started, pid: %d\n", id, getpid());
  while (1) {
    // CPU-bound work (infinite loop)
    for (volatile long i = 0; i < 1000000000; i++);
    printf("Process %d still running, pid: %d\n", id, getpid());
  }
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("No arguments provided.");
    return 1;
  }

  struct timeval tv;
  gettimeofday(&tv, NULL);  // Get current time
  printf("Seconds: %ld\nMicroseconds: %ld\n", tv.tv_sec, tv.tv_usec);

  num_children = argc - 1;
  int priorities[num_children] = {};
  // int priorities[num_children] = {10, 0, -10};  // priorities are now set via
  // arguments

  for (int i = 0; i < num_children; i++) {
    priorities[i] = atoi(argv[i + 1]);
    if (!priorities[i] && priorities[i] != 0) {
      perror("Invalid priority in arguments");
      exit(1);
    }
    if (priorities[i] > 20 || priorities[i] < -20) {
      perror("Invalid priority in arguments");
      exit(1);
    }
  }

  pid_t pids[num_children];
  // Create multiple CPU-bound processes with different priorities
  for (int i = 0; i < num_children; i++) {
    pids[i] = fork();
    if (pids[i] < 0) {
      perror("fork");
      exit(1);
    }

    if (pids[i] == 0) {
      printf("The initial priority is %d\n",
             getpriority(PRIO_PROCESS, getpid()));

      // Set the priority of this process
      if (setpriority(PRIO_PROCESS, getpid(), priorities[i]) < 0) {
        perror("setpriority");
        exit(1);
      }
      // In child process
      printf("Child %d (pid: %d) with priority %d\n", i + 1, getpid(),
             priorities[i]);
      // Start the CPU-bound task
      cpu_bound_task(i + 1);
      exit(0);  // Shouldn't reach here
    }
  }

  // Parent process: wait for all child processes
  for (int i = 0; i < num_children; i++) {
    wait(NULL);  // Waiting for child processes (will block)
  }

  return 0;
}