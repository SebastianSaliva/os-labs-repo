// qreader.c

#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define SEM_WRITER "/qwriter"
#define SEM_READER "/qreader"

struct mesg_buffer {
  long mesg_type;
  int mesg_text;
};

int main() {
  sem_t *semaphore_writer = sem_open(SEM_WRITER, O_CREAT, 0666, 0);
  if (semaphore_writer == SEM_FAILED) {
    perror("error opening writer semaphore");
    exit(EXIT_FAILURE);
  }

  sem_t *semaphore_reader = sem_open(SEM_READER, O_CREAT, 0666, 0);
  if (semaphore_reader == SEM_FAILED) {
    perror("error opening reader semaphore");
    exit(EXIT_FAILURE);
  }
  printf("semr:%d\n", semaphore_reader);
  printf("semw:%d\n", semaphore_writer);
  key_t key;
  int msgid;
  struct mesg_buffer message;
  // Create a unique key
  key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    return 1;
  }
  // msgget creates a message queue
  // and returns identifier
  msgid = msgget(key, 0666 | IPC_CREAT);
  printf("Waiting! msgid:%d \n", msgid);

  sem_wait(semaphore_writer);
  long int sum = 0;
  int i = 0;
  for (i; i < 1000000; i++) {
    // msgrcv to receive message
    msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0);
    sum += message.mesg_text;
    sem_post(semaphore_reader);
    sem_wait(semaphore_writer);
  }

  printf("\nSum: %ld\n", sum);
  msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0);

  double clocks = clock() - message.mesg_text;
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;

  printf("Time Elapsed: %f seconds\n", t_s);
  printf("              %f milli seconds\n", t_s * 1000);
  printf("              %f micro seconds\n", t_s * 1000000);
  printf("              %f nano seconds\n", t_s * 1000000000);
  sem_post(semaphore_reader);
  sem_wait(semaphore_writer);
  // to destroy the message queue
  msgctl(msgid, IPC_RMID, NULL);

  sem_post(semaphore_reader);

  sem_close(semaphore_reader);
  sem_close(semaphore_writer);

  return 0;
}