#include "functions.h"

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double data = 0;
int data_buffer_full = 0;
int quit = 0;
pthread_cond_t cond_wait_read;
pthread_cond_t cond_wait_processed;
extern pthread_mutex_t mutex;

/**
 * @brief gathers a number from the user, saves it to the data buffer and waits
 * till its processed to repeat
 *
 */
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

/**
 * @brief calculates the arcsine of the number in data buffer if its between
 * valid range
 *
 *  waits till the data buffer is full, then
 *  if the data if between 0-1 the arcsine of it is calculated and printed
 *  if the data is larger than 100 the program quits
 *  else indicates the user the data is invalid
 *
 *  after the checks, the data buffer full indicator is set to false
 *
 */
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