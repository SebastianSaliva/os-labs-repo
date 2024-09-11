#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "functions.h"

int pid_exists(pid_t pid) {
  if (pid <= 0) {
    return 0;  // Invalid PID
  }

  return kill(pid, 0) == 0 || errno != ESRCH;
}

int main(int argc, char* argv[]) {
  pid_t pidArr[5] = {0};
  if (argc > 1) {
    for (int i = 0; i < 6; i++) {
      if (argv[i + 1]) {
        int a = atoi(argv[i + 1]);
        pidArr[i] += a;
      }
    }
  } else {
    printf("No arguments provided. Please try again.\n");
    return 0;
  }

  while (1) {
    int running = 0;

    for (int i = 0; i < 5; i++) running += pid_exists(pidArr[i]);

    if (!running) {
      printf("No infinite counter running, goodbye!\n");
      return 0;
    } else {
      printf("\nPIDS | ");
      for (int i = 0; i < 5; i++)
        if (pidArr[i]) printf("%d | ", pidArr[i]);

      printf("\n");
    }

    char codeNid[100];

    printf("1. Stop process.\n");
    printf("2. Continue process.\n");
    printf("3. Reset counter.\n");
    printf("4. Change process direction.\n");
    printf("5. Kill process.\n");
    printf("Format Examp:3 14159\n");
    printf("<code> <pid>:");
    fgets(codeNid, 100, stdin);

    if (codeNid[1] == ' ' && strlen(codeNid) > 3) {
      char* code;
      char* pidstr;
      code = strtok(codeNid, " ");
      pidstr = strtok(NULL, " ");

      int selec = atoi(code);
      int pidi = atoi(pidstr);

      pid_t pid = (pid_t)pidi;

      int pidExists = pid_exists(pid);

      if (pidExists) {
        if (selec == 1)
          kill(pid, SIGSTOP);

        else if (selec == 2)
          kill(pid, SIGCONT);

        else if (selec == 3)
          kill(pid, SIGUSR1);

        else if (selec == 4)
          kill(pid, SIGUSR2);

        else if (selec == 5) {
          kill(pid, SIGKILL);
          for (int i = 0; i < 5; i++)
            if (pidArr[i] == pid) pidArr[i] = 0;

        } else
          printf("Invalid code.\n");

      } else
        printf("Invalid pid.\n");

    } else
      printf("Invalid input.\n");
  }
  return 0;
}
