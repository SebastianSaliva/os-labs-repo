#include <semaphore.h>

// must be set on the same for 2 process to use the same sem
#define SEM_WRITER "/semwriter"
#define SEM_READER "/semreader"

int main() {
  // sems: starts with f 0 or 1
  // when wait, incremets f and wait for f to be 0 to continue
  // when post, decrements f
  // sem_t *semaphore_writer = sem_open(SEM_WRITER, O_CREAT, 0666, 0);
  // sem_t *semaphore_reader = sem_open(SEM_READER, O_CREAT, 0666, 0);
  // sem_wait(semaphore_reader);
  // sem_post(semaphore_reader);
  // sem_close(semaphore_reader);
  // sem_close(semaphore_writer);
  // if (semaphore_writer == SEM_FAILED || semaphore_reader == SEM_FAILED) {
  //   perror("error openingsemaphore");
  //   exit(EXIT_FAILURE);
  // }
}