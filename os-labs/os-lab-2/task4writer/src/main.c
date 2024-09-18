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

#define SEM_WRITER "/writer"
#define SEM_READER "/reader"

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
  printf("writing to addr block: %x", data);

  // Write to shared memory

  clock_t s = clock();

  int i = 0;
  for (i; i < 1000000; i++) {
    data[i] = i + 1;
  }
  data[i] = s;

  sem_post(semaphore_writer);

  sem_wait(semaphore_reader);

  sem_close(semaphore_reader);
  sem_close(semaphore_writer);

  // Detach from shared memory
  shmdt(data);

  return 0;
}
