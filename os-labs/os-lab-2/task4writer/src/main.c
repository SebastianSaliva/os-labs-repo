// writer.c
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>

#define SHM_SIZE 1000001 * sizeof(int)  // Shared memory size

#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

int main() {
  key_t key;
  int shmid;
  int *data;

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    exit(EXIT_FAILURE);
  }

  sem_t *semaphore_producer = sem_open(SEM_PRODUCER, O_CREAT, 0666, 0);
  if (semaphore_producer == SEM_FAILED) {
    perror("error opening producer semaphore");
    exit(EXIT_FAILURE);
  }

  sem_t *semaphore_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0666, 0);
  if (semaphore_consumer == SEM_FAILED) {
    perror("error opening consumer semaphore");
    exit(EXIT_FAILURE);
  }

  // Create a shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    exit(EXIT_FAILURE);
  }

  // Attach to the shared memory segment
  data = (int *)shmat(shmid, NULL, 0);
  if (data == (int *)-1) {
    perror("shmat failed");
    exit(EXIT_FAILURE);
  }

  // Write to shared memory

  int i = 0;

  clock_t s;
  s = clock();

  for (i; i < 1000000; i++) {
    data[i] = i + 1;
  }
  data[i] = s;

  sem_post(semaphore_producer);

  sem_wait(semaphore_consumer);

  sem_close(semaphore_consumer);
  sem_close(semaphore_producer);

  // Detach from shared memory
  shmdt(data);

  return 0;
}