

#include "functions.h"

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

uint8_t input_buffer[10000];
int n_read_values = 0;
float processed_buffer[10000];
int n_processed_values = 0;

void* file_tester() {
  FILE* file;
  int* file_existed = malloc(sizeof(int));

  // Check if the file exists
  if ((file = fopen("data.txt", "r"))) {
    fclose(file);
    *file_existed = 1;
  } else {
    *file_existed = 0;
    file = fopen("data.txt", "w");
    srand(time(NULL));

    for (int i = 0; i < 10000; i++) {
      uint8_t random_value = (uint8_t)(rand() % 256);
      fprintf(file, "%u\n", random_value);
    }
    fclose(file);
  }

  return file_existed;  // File created and filled with random values
};

void* file_reader() {
  clock_t start = clock();

  FILE* file;
  file = fopen("data.txt", "r");

  for (int i = 0; i < 10000; i++) {
    char line[10];
    fgets(line, sizeof(line), file);
    uint8_t num = (uint8_t)atoi(line);
    input_buffer[i] = num;
    n_read_values++;
  }
  fclose(file);

  double clocks = clock() - start;
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;
  printf("reader thread took: %f milli seconds\n", t_s * 1000);
}
void* array_calculator() {
  clock_t start = clock();
  int i = 0;
  while (i < 10000) {
    if (i < n_read_values) {
      int r = (int)input_buffer[i];
      float yinit = r / 2;

      float ynp = 0.5 * (yinit + r / yinit);
      float yn;
      for (int n = 0; n <= 10; n++) {
        yn = 0.5 * (ynp + r / ynp);
        ynp = yn;
      }
      processed_buffer[i] = yn;
      n_processed_values++;
      i++;
    }
  }

  double clocks = clock() - start;
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;
  printf("processing thread took: %f milli seconds\n", t_s * 1000);
}

void* file_writer() {
  clock_t start = clock();
  FILE* file;
  file = fopen("sqrt.txt", "w");
  int i = 0;
  while (i < 10000) {
    if (i < n_processed_values) {
      fprintf(file, "%f\n", processed_buffer[i]);
      i++;
    }
  }
  fclose(file);

  double clocks = clock() - start;
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;
  printf("writer thread took: %f milli seconds\n", t_s * 1000);
}