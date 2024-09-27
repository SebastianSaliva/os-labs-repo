#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

pthread_mutex_t mutex;

int main() {
  pthread_t p_reader;
  pthread_t p_processor;

  pthread_mutex_init(&mutex, NULL);

  pthread_create(&p_reader, NULL, ReadData, NULL);
  pthread_create(&p_processor, NULL, PrintData, NULL);

  pthread_join(p_reader, NULL);
  pthread_join(p_processor, NULL);

  return 0;
}
