// reader.c
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

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
    return 1;
  }

  // sem_unlink(SEM_PRODUCER);
  // sem_unlink(SEM_CONSUMER);

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

  // Locate the shared memory segment
  // shmid = shmget(key, SHM_SIZE, 0666);
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

  int sum = 0;

  int i = 0;

  sem_wait(semaphore_producer);

  for (i; i < 1000000; i++) {
    sum += data[i];
  }
  printf("\nSum: %d\n", sum);

  double clocks = clock() - data[i];
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;

  printf("Time Elapsed: %f seconds\n", t_s);
  printf("              %f milli seconds\n", t_s * 1000);
  printf("              %f micro seconds\n", t_s * 1000000);
  printf("              %f nano seconds\n", t_s * 1000000000);
  sem_post(semaphore_consumer);

  sem_close(semaphore_consumer);
  sem_close(semaphore_producer);

  // Detach from shared memory
  shmdt(data);

  // Optionally, destroy the shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}