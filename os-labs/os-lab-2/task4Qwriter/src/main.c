// qwriter.c

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

// structure for message queue
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

  key_t key;
  int msgid;
  struct mesg_buffer message;
  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    exit(EXIT_FAILURE);
  }
  // msgget creates a message queue
  // and returns identifier
  msgid = msgget(key, 0666 | IPC_CREAT);

  // msgsnd to send message
  printf("Writing %d!\n", msgid);
  clock_t s = clock();
  int i = 0;
  message.mesg_type = 1;
  for (i; i < 1000000; i++) {
    message.mesg_text = i + 1;
    msgsnd(msgid, &message, sizeof(message.mesg_text), 0);
    sem_post(semaphore_writer);
    sem_wait(semaphore_reader);
  }

  message.mesg_text = s;
  msgsnd(msgid, &message, sizeof(message.mesg_text), 0);
  sem_post(semaphore_writer);
  sem_wait(semaphore_reader);

  sem_post(semaphore_writer);
  printf("Done Wrinting.");
  sem_wait(semaphore_reader);

  sem_close(semaphore_reader);
  sem_close(semaphore_writer);

  return 0;
}