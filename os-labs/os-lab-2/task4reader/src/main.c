// reader.c
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

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
    return 1;
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

  // Locate the shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    exit(1);
  }

  // map the block into the process adress space
  data = (int *)shmat(shmid, NULL, 0);

  printf("address of the block: %x\n", data);

  if (data == (int *)-1) {
    perror("shmat failed");
    exit(1);
  }

  // Read from shared memory

  sem_wait(semaphore_writer);

  long int sum = 0;
  int i = 0;
  for (i; i < 1000000; i++) {
    sum += data[i];
  }
  printf("\nSum: %ld\n", sum);

  double clocks = clock() - data[i];
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;

  printf("Time Elapsed: %f seconds\n", t_s);
  printf("              %f milli seconds\n", t_s * 1000);
  printf("              %f micro seconds\n", t_s * 1000000);
  printf("              %f nano seconds\n", t_s * 1000000000);

  sem_post(semaphore_reader);

  sem_close(semaphore_reader);
  sem_close(semaphore_writer);

  // Detach from shared memory
  shmdt(data);

  // Optionally, destroy the shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}