#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "functions.h"
int main() {
  PrintTest();

  int pid = fork();

  if (!pid) {
    // in child process
    printf("chere\n");
    char *com = "ls";
    char *argument_list[] = {"ls", "-l", NULL};

    execlp("ls", "ls", NULL);
    printf("cafter\n");
    // if (stat == -1) {
    //   printf("process did not terminate correctly\n");
    //   exit(1);
    // }

  } else {
    // in parent process
    printf("phere\n");
    int *stat;
    waitpid(pid, stat, 0);
    printf("pafter\n");
  }

  return 0;
}
