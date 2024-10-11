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

#include "functions.h"

int should_launch = 0;

int main() {
  // set up zombie killer
  struct sigaction sa;
  sa.sa_handler = SigchldHandler;
  sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
  if (sigaction(SIGCHLD, &sa, 0) == -1) {
    perror("sigaction");
    exit(1);
  }

  // change timer signal and setup timer
  int signum = SIGUSR1;
  struct sigevent event;
  timer_t timer_id;
  event.sigev_notify = SIGEV_SIGNAL;
  event.sigev_signo = signum;

  timer_create(CLOCK_REALTIME, &event, &timer_id);

  struct sigaction action;
  action.sa_handler = SupervisorSignalHandler;
  action.sa_flags = 0;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGTERM, &action, NULL);

  // set timer params
  struct itimerspec timer_params;
  timer_params.it_value.tv_sec = 1;
  timer_params.it_value.tv_nsec = 500 * 1000000;
  timer_params.it_interval.tv_sec = 1;
  timer_params.it_interval.tv_nsec = 500 * 1000000;

  // start timer
  timer_settime(timer_id, 0, &timer_params, NULL);

  // wait for should lauch, which is true if GetPidByName returns a valid id
  while (1) {
    usleep(100000);
    if (should_launch) {
      should_launch = 0;
      LaunchNewImuHandler();
    }
  }

  return 0;
}
