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

/**
 * @brief if the file data.txt doesn't exist, its created and filled with random
 * nums
 *
 * @return indication of whether the file existed or not
 *
 */
void* FileTester() {
  FILE* file;
  int* file_existed = malloc(sizeof(int));

  if ((file = fopen("data.txt", "r"))) {
    fclose(file);
    *file_existed = 1;
  } else {
    *file_existed = 0;
    file = fopen("data.txt", "w");
    srand(time(NULL));
    // write random 8 bit num to data.txt
    for (int i = 0; i < 10000; i++) {
      uint8_t num = (uint8_t)(rand() % 256);
      fprintf(file, "%u\n", num);
    }
    fclose(file);
  }

  return file_existed;
};

/**
 * @brief reads each line of data.txt and saves the number in each line to
 * input_buffer
 *
 */
void* FileReader() {
  clock_t start = clock();

  FILE* file;
  file = fopen("data.txt", "r");

  for (int i = 0; i < 10000; i++) {
    char line[10];
    fgets(line, sizeof(line), file);  // read value from data.txt
    uint8_t num = (uint8_t)atoi(line);
    input_buffer[i] = num;
    n_read_values++;
  }
  fclose(file);

  double clocks = clock() - start;
  double seconds_taken = ((double)clocks) / CLOCKS_PER_SEC;
  printf("reader thread took: %f milli seconds\n", seconds_taken * 1000);
}

/**
 * @brief reads values from input_buffer, calculates its square root, and saves
 * result in processed_buffer
 *
 */
void* ArrayCalculator() {
  clock_t start = clock();
  int i = 0;
  while (i < 10000) {
    // check if i index was written
    if (i < n_read_values) {
      // sqrt calculator alg
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
  double seconds_taken = ((double)clocks) / CLOCKS_PER_SEC;
  printf("processing thread took: %f milli seconds\n", seconds_taken * 1000);
}
/**
 * @brief creates a file called sqrt.txt where the sqrt of the values will be
 * written
 *
 */
void* FileWriter() {
  clock_t start = clock();
  FILE* file;
  file = fopen("sqrt.txt", "w");
  int i = 0;
  while (i < 10000) {
    // check if i index was already processed
    if (i < n_processed_values) {
      fprintf(file, "%f\n", processed_buffer[i]);
      i++;
    }
  }
  fclose(file);
}

int main() {
  pthread_t p_file_test;
  int* file_existed;

  pthread_create(&p_file_test, NULL, FileTester, NULL);
  pthread_join(p_file_test, (void**)&file_existed);
  printf("File existed: %d\n", *file_existed);
  free(file_existed);

  pthread_t p_reader;
  pthread_t p_calculator;
  pthread_t p_writer;
  pthread_create(&p_reader, NULL, FileReader, NULL);
  pthread_create(&p_calculator, NULL, ArrayCalculator, NULL);
  pthread_create(&p_writer, NULL, FileWriter, NULL);
  pthread_join(p_reader, NULL);
  pthread_join(p_calculator, NULL);
  pthread_join(p_writer, NULL);
  return 0;
}
