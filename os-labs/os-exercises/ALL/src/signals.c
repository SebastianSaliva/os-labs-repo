#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int user1_signal_received_n_time = 0;
int user2_signal_received_n_time = 0;

void signal_handler(int signum) {
  if (signum == SIGUSR1) {
    user1_signal_received_n_time++;

  } else if (signum == SIGUSR2) {
    user2_signal_received_n_time++;

  } else if (signum == SIGINT) {
    printf("Interrupted modified");
    exit(0);
  }
}

int main() {
  struct sigaction sa;
  sa.sa_handler = signal_handler;

  /* When this process receives these signals, they will be detected in
   * signal_handler */
  sigaction(SIGINT, &sa, NULL);
  signal(SIGUSR1, signal_handler);
  signal(SIGUSR2, signal_handler);
  return 0;
}