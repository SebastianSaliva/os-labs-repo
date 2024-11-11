#include <asm/signal.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  pid_t pid_struct_is_also_an_int;
  pid_t a_pid_is_a_Process_IDentidier;
  pid_t this_process_id = getpid();
  pid_t another_process_pid = 999999;

  /* you can send signals */

  kill(9999999, SIGSTOP);
  kill(9999999, SIGCONT);
  kill(9999999, SIGKILL);
  kill(9999999, SIGUSR1);  // user defined
  kill(9999999, SIGUSR2);  // user defined

  /* Forking */

  pid_t pid = fork();

  /* There are now two processes running this line */
  /* The one created due to the fork is the child. */
  /* If the pid returned by fork is 0, we are currently on the child process */
  /* Else its the parent and pid is the pid of the child */

  if (pid == 0) {
    printf("Im a child ! my parent is: %d \n", getppid());
  }
  if (pid != 0) {
    printf("Im a parent! my child  is: %d", pid);
  }
  printf("I may be the child or the parent... \n");

  /* Lets turn the child process into another program */
  if (pid == 0) {
    printf("Im a child and im replacing myself with another process \n");
    execl("<some_c.exe_file_name>", "<same_c.exe_file_name>",
          NULL);  // NULL is argv
    exit(1);      // this shouldn't be executed, but handles error
  }
  printf("Im most def a parent");

  /* You can wait for child process to finish executing before proceeding */
  int *status;
  waitpid(pid, status, 0);
  printf("Im most def a parent, but my child died :(");
}