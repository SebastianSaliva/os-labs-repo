
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"

int main() {
  pthread_t p_file_test;
  int* file_existed;

  pthread_create(&p_file_test, NULL, file_tester, NULL);
  pthread_join(p_file_test, (void**)&file_existed);
  printf("File existed: %d\n", *file_existed);
  free(file_existed);

  pthread_t p_reader;
  pthread_t p_calculator;
  pthread_t p_writer;
  pthread_create(&p_reader, NULL, file_reader, NULL);
  pthread_create(&p_calculator, NULL, array_calculator, NULL);
  pthread_create(&p_writer, NULL, file_writer, NULL);
  pthread_join(p_reader, NULL);
  pthread_join(p_calculator, NULL);
  pthread_join(p_writer, NULL);
  return 0;
}
