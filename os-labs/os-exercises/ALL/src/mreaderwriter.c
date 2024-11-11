/* SHARED MEMORY */
#include <fcntl.h>
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

/* S = S ared */
/* H =  H     */
/* M = Memory */

/* Shared memory size to fit N integers. */
#define N 100
#define SHM_SIZE N * sizeof(int)
void reading_from_SH_ared_M_em() {
  /* Create key 4 shm */
  key_t key = ftok("/tmp", 65);
  if (key == -1) printf("error ftok");

  /* Create shm */
  int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) printf("error shmid");

  /* Attach 2 shm */
  int *data_ptr = (int *)shmat(shmid, NULL, 0);
  if (data_ptr == (int *)-1) printf("error shmat");
  printf("shm address: %x", data_ptr);

  /* Read from shm */
  for (int i = 0; i < SHM_SIZE; i++) printf("%d read", data_ptr[i]);

  /* Detach from shm */
  shmdt(data_ptr);

  /* Destroy shm when appropiate */
  int done_reading, done_writing = 1;
  if (done_reading && done_writing) {
    shmctl(shmid, IPC_RMID, NULL);
  }
}

void writing_to_SH_ared_M_em() {
  /* Create key 4 shm */
  key_t key = ftok("/tmp", 65);
  if (key == -1) printf("error ftok");

  /* Create shm */
  int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) printf("error shmid");

  /* Attach 2 shm */
  int *data_ptr = (int *)shmat(shmid, NULL, 0);
  if (data_ptr == (int *)-1) printf("error shmat");
  printf("shm address: %x", data_ptr);

  /* Write 2 shm */
  for (int i = 0; i < SHM_SIZE; i++) data_ptr[i] = i;

  /* Detach from shm */
  shmdt(data_ptr);

  /* Destroy shm when appropiate */
  int done_reading, done_writing = 0;
  if (done_reading && done_writing) {
    shmctl(shmid, IPC_RMID, NULL);
  }
}
int main() { return 0; }