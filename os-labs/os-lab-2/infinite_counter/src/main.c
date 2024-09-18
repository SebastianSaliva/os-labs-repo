#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int counter = 0;
int direction = 1;

void handler(int signum) {
  if (signum == SIGUSR1) {
    counter = 0;

  } else if (signum == SIGUSR2) {
    direction *= -1;

  } else if (signum == SIGINT) {
    printf("Interrupt");
  }
}

int main() {
  struct sigaction sa;
  sa.sa_handler = handler;
  sigaction(SIGINT, &sa, NULL);

  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);
  while (1) {
    printf("I’m (%d)counting, and my count is %d\n", getpid(), counter);
    counter += direction;
    sleep(1);
  }

  return 0;
}
