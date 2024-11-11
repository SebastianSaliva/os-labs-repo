#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintTest() { printf("Test\n"); }

int GenerateRandNumber(int max) {
  srand(time(NULL));
  int r = rand() % max + 1;
  return r;
}

int GetUserInputInt() {
  int input;
  printf("Input: ");
  scanf("%d", &input);
  return input;
}

void WaysToCalculateTimeTaken() {
  double start = clock();
  sleep(3);
  double end = clock();
  double clocks = end - start;
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;

  printf("Time Elapsed: %f seconds\n", t_s);
  printf("              %f milli seconds\n", t_s * 1000);
  printf("              %f micro seconds\n", t_s * 1000000);
  printf("              %f nano seconds\n", t_s * 1000000000);
}