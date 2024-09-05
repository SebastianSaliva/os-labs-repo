#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "functions.h"

int main() {
  pid_t idp0 = getpid();

  pid_t idp1 = fork();

  pid_t idp2 = 1;
  pid_t idp3 = 1;

  if (idp1) idp2 = fork();

  if (idp2 && idp1) idp3 = fork();

  if (idp1 < 0 || idp2 < 0 || idp3 < 0) perror("fork fail");

  if (!idp1 || !idp2 || !idp3) {
    printf("I'm a child, and my id is: %d\n", getpid());

    pid_t idep1 = fork();
    pid_t idep2 = 1;

    if (idep1) idep2 = fork();

    if (idep1 < 0 || idep2 < 0) perror("fork fail");

    if (!idep1 || !idep2) {
      execl("greetings", "greetings", NULL);

    } else {
      int *status;
      waitpid(idep1, status, 0);
      waitpid(idep2, status, 0);
    }
  } else {
    int *status;

    waitpid(idp1, status, 0);
    waitpid(idp2, status, 0);
    waitpid(idp3, status, 0);
  }

  return 0;
}
