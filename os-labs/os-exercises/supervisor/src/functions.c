#include "functions.h"

#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
extern int should_launch;

/// @brief finds the pid of a process with the name in process_name
/// @param process_name name of process to find
/// @return pid of process or -1 if it is not found
int GetPidByName(const char *process_name) {
  char command[256];
  snprintf(command, sizeof(command), "pgrep -x %s", process_name);
  FILE *fp = popen(command, "r");
  if (fp == NULL) {
    perror("popen");
    return -1;
  }
  int pid = -1;
  if (fscanf(fp, "%d", &pid) == 1) {
    // Successfully retrieved a PID
  }
  pclose(fp);
  return pid;
}

/// @brief creates new imu_handler process
/// @return pid of process created
int LaunchNewImuHandler() {
  printf("Starting new imu_handler...\n");

  // get rid of zombies
  int pid_to_del;
  while (pid_to_del = GetPidByName("imu_handler") != -1)
    kill(pid_to_del, SIGTERM);

  int imu_pid = fork();

  if (imu_pid == 0) {
    // launch new process
    execlp("./imu_handler", "./imu_handler", NULL);
    perror("execlp failed");
    exit(0);
  }
  return imu_pid;
}

/// @brief handles both termination and timer signals
/// @param signum signal received
void SupervisorSignalHandler(int signum) {
  // on termination
  if (signum == SIGTERM) {
    char buffer[100] = "Closing Supervisor.\n";
    write(1, buffer, strlen(buffer));

    // kill driver processes and exit
    int pid_to_del;
    while (pid_to_del = GetPidByName("imu_handler") != -1) {
      kill(pid_to_del, SIGTERM);
      usleep(100000);
    }
    exit(0);
  }

  // on timer signal
  if (signum == SIGUSR1) {
    char buffer[100];

    // get pid
    int imu_handler_pid = GetPidByName("imu_handler");
    snprintf(buffer, sizeof(buffer),
             "Supervising: imu_handler %d; status: ok!\n", imu_handler_pid);

    // check if valid, if not, set should_lauch to true
    if (imu_handler_pid == -1) {
      should_launch = 1;
      snprintf(buffer, sizeof(buffer),
               "Supervising: imu_handler %d; status: down.\n", imu_handler_pid);
    }

    write(1, buffer, strlen(buffer));
    return;
  }
}

/// @brief kills child that misbehaves >:(
/// @param signum signal received
void SigchldHandler(int signum) {
  int status;
  pid_t pid;
  while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
    printf("Child process %d terminated\n", pid);
  }
}