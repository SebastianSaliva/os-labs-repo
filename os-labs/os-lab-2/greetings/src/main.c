#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("hello there, I’m process %d \n", getpid());
  sleep(10);
  printf("I'm (P : %d) done, bye!\n", getpid());
  return 0;
}
