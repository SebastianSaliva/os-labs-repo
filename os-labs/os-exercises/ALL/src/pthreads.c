#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
pthread_cond_t cond_wait_read;
pthread_cond_t cond_wait_processed;
void* PrintData() {
  while (!quit) {
    pthread_mutex_lock(&mutex);

    // wait for there to be data in the buffer
    while (!data_buffer_full) {
      pthread_cond_wait(&cond_wait_read, &mutex);
    }

    if (0 <= data && data <= 1) {
      double asin_num = asin(data);
      printf("Arcsine of %lf: %lf\n", data, asin_num);
    } else if (data >= 100) {
      printf("Number greater than 100, quiting!\n");
      quit = 1;

    } else {
      printf("Invalid Number!\n");
    }
    // signal that the data was processed
    data_buffer_full = 0;
    pthread_cond_signal(&cond_wait_processed);
    pthread_mutex_unlock(&mutex);
  }
}

void* ReadData() {
  while (!quit) {
    pthread_mutex_lock(&mutex);

    // wait till there is no data in the buffer
    while (data_buffer_full) {
      pthread_cond_wait(&cond_wait_processed, &mutex);
    }
    if (quit) break;
    printf("Enter number from 0-1: ");
    scanf("%lf", &data);

    // signal that a value was read
    data_buffer_full = 1;
    pthread_cond_signal(&cond_wait_read);
    pthread_mutex_unlock(&mutex);
  }
}

void* FunctionThatRunsAsThread() {}
void* FunctionThatRunsAsThreadArg(void* arg) {}
pthread_mutex_t mutex;

int main() {
  /* Basic Explanation */
  pthread_t p_some_thread;
  pthread_create(&p_some_thread, NULL, FunctionThatRunsAsThread, NULL);
  pthread_join(p_some_thread, NULL);  // wait for thread to finish running

  /* Returning */
  int* thread_returned;
  int arg = 1;
  pthread_t p_some_thread;
  pthread_create(&p_some_thread, NULL, FunctionThatRunsAsThread, (void*)&arg);
  pthread_join(p_some_thread,
               (void**)&thread_returned);  // wait for thread to finish running
  int value = *thread_returned;
  free(thread_returned);

  pthread_t p_reader;
  pthread_t p_processor;

  pthread_mutex_init(&mutex, NULL);

  pthread_create(&p_reader, NULL, ReadData, NULL);
  pthread_create(&p_processor, NULL, PrintData, NULL);

  pthread_join(p_reader, NULL);
  pthread_join(p_processor, NULL);

  return 0;
}
