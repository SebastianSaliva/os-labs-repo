#include "functions.h"

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern double tan_arr[1000000];

/**
 * @brief sums up the segment (from offset to offset+200000) of tan array
 *
 * @param[in] segment_offset index from where to start the segment
 * @return the sum of the segment
 */
void* SumSegment(void* segment_offset) {
  int* offset = (int*)segment_offset;

  double* segment_sum = malloc(sizeof(double));
  *segment_sum = 0;
  for (int i = 0; i < 200000; i++) {
    *segment_sum += tan_arr[*offset + i];
  }

  return segment_sum;
}
