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

int counter = 0;

void TermSigHandler(int signum) {
  if (signum == SIGTERM) exit(0);
}
void DefaultTimerSignalHandler() {
  printf("Timer alarm signal received: %d\n", counter);
  counter++;
}
void CustomTimerSignalHandler(int signum) {
  if (signum == SIGUSR1) {
    printf("Timer USR1 signal received: %d\n", counter);
    counter++;
  }
}

// int main() {
//   // set up action handlers
//   // 1. SIGTERM
//   struct sigaction action;
//   action.sa_handler = TermSigHandler;
//   action.sa_flags = 0;
//   sigaction(SIGTERM, &action, NULL);
//   // 2. Default Timer
//   struct sigaction action_timer;
//   action_timer.sa_handler = DefaultTimerSignalHandler;
//   action_timer.sa_flags = 0;
//   sigaction(SIGALRM, &action_timer, NULL);

//   // set up timer
//   // create the timer
//   timer_t timer_id;
//   struct itimerspec timer_params;
//   timer_create(CLOCK_REALTIME, NULL, &timer_id);  // NULL -> SIGNAL_ALRM
//   // modify timer parameters
//   int period_ms = 200;
//   timer_params.it_value.tv_sec = 0;
//   timer_params.it_value.tv_nsec = period_ms * 1E6;
//   timer_params.it_interval.tv_sec = 0;
//   timer_params.it_interval.tv_nsec = period_ms * 1E6;
//   // start timer
//   timer_settime(timer_id, 0, &timer_params, NULL);

//   while (1) {
//     printf("Hello World\n");
//     sleep(1);
//   }

//   return 0;
// }

int main() {
  // set up action handlers
  // 1. SIGTERM
  struct sigaction action;
  action.sa_handler = TermSigHandler;
  action.sa_flags = 0;
  sigaction(SIGTERM, &action, NULL);

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
  action_timer.sa_handler = CustomTimerSignalHandler;
  action_timer.sa_flags = 0;
  sigaction(SIGUSR1, &action_timer, NULL);

  int period_ms = 200;
  timer_params.it_value.tv_sec = 0;
  timer_params.it_value.tv_nsec = period_ms * 1E6;
  timer_params.it_interval.tv_sec = 0;
  timer_params.it_interval.tv_nsec = period_ms * 1E6;
  // start timer
  timer_settime(timer_id, 0, &timer_params, NULL);

  while (1) {
    printf("Hello World\n");
    sleep(1);
  }

  return 0;
}
