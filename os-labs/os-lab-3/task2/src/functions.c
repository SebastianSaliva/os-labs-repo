#include "functions.h"

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern double x[1000000];

void* SumSegment(void* param) {
  // for (int i = 0; i < 1000000; i++) {
  //   printf("%d\n", x[i]);
  // }
  int* offset = (int*)param;

  double* segsum = malloc(sizeof(double));
  *segsum = 0;
  for (int i = 0; i < 200000; i++) {
    *segsum += x[*offset + i];
  }

  return (void*)segsum;
}
