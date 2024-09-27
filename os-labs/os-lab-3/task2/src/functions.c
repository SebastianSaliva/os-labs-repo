#include "functions.h"

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern double tan_arr[1000000];

void* SumSegment(void* param) {
  // for (int i = 0; i < 1000000; i++) {
  //   printf("%d\n", x[i]);
  // }
  int* offset = (int*)param;

  double* segsum = malloc(sizeof(double));
  *segsum = 0;
  for (int i = 0; i < 200000; i++) {
    *segsum += tan_arr[*offset + i];
  }

  return segsum;
}
