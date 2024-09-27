#include "functions.h"

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double num = 0;
int data_buffer_full = 0;
int quit = 0;
pthread_cond_t cond_wait_read;
pthread_cond_t cond_wait_processed;
extern pthread_mutex_t mutex;

void* ReadData(void* param) {
  while (!quit) {
    pthread_mutex_lock(&mutex);
    while (data_buffer_full) {
      pthread_cond_wait(&cond_wait_processed, &mutex);
    }
    if (quit) break;
    printf("Enter number from 0-1: ");
    scanf("%lf", &num);
    data_buffer_full = 1;
    pthread_cond_signal(&cond_wait_read);
    pthread_mutex_unlock(&mutex);
  }
}

void* PrintData(void* param) {
  while (!quit) {
    pthread_mutex_lock(&mutex);
    while (!data_buffer_full) {
      pthread_cond_wait(&cond_wait_read, &mutex);
    }

    if (0 <= num && num <= 1) {
      double asin_num = asin(num);
      printf("Arcsine of %lf: %lf\n", num, asin_num);
    } else if (num >= 100) {
      printf("Number greater than 100, quiting!\n");
      quit = 1;

    } else {
      printf("Invalid Number!\n");
    }

    data_buffer_full = 0;
    pthread_cond_signal(&cond_wait_processed);
    pthread_mutex_unlock(&mutex);
  }
}