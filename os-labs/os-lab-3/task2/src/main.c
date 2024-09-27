#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

double tan_arr[1000000];

int main() {
  for (int i = 0; i < 1000000; i++) {
    tan_arr[i] = tan(i + 1);
  }
  clock_t start = clock();
  pthread_t p_segment0;
  pthread_t p_segment1;
  pthread_t p_segment2;
  pthread_t p_segment3;
  pthread_t p_segment4;

  int offset0 = 0;
  int offset1 = 200000;
  int offset2 = 400000;
  int offset3 = 600000;
  int offset4 = 800000;

  double* seg0sum;
  double* seg1sum;
  double* seg2sum;
  double* seg3sum;
  double* seg4sum;

  double total_sum = 0;

  pthread_create(&p_segment0, NULL, SumSegment, (void*)&offset0);
  pthread_create(&p_segment1, NULL, SumSegment, (void*)&offset1);
  pthread_create(&p_segment2, NULL, SumSegment, (void*)&offset2);
  pthread_create(&p_segment3, NULL, SumSegment, (void*)&offset3);
  pthread_create(&p_segment4, NULL, SumSegment, (void*)&offset4);

  pthread_join(p_segment0, (void**)&seg0sum);

  total_sum += *seg0sum;
  pthread_join(p_segment1, (void**)&seg1sum);

  total_sum += *seg1sum;
  pthread_join(p_segment2, (void**)&seg2sum);

  total_sum += *seg2sum;
  pthread_join(p_segment3, (void**)&seg3sum);

  total_sum += *seg3sum;
  pthread_join(p_segment4, (void**)&seg4sum);

  total_sum += *seg4sum;

  double clocks = clock() - start;
  double t_s = ((double)clocks) / CLOCKS_PER_SEC;
  printf("Result thread: %lf\n", total_sum);
  printf("using threads took: %f milli seconds\n", t_s * 1000);

  free(seg0sum);
  free(seg1sum);
  free(seg2sum);
  free(seg3sum);
  free(seg4sum);

  start = clock();

  for (int i = 0; i < 1000000; i++) {
    tan_arr[i] = tan(i + 1);
  }
  double sum = 0;
  for (int i = 0; i < 1000000; i++) {
    sum += tan_arr[i];
  }

  clocks = clock() - start;
  t_s = ((double)clocks) / CLOCKS_PER_SEC;
  printf("Result main: %lf\n", sum);
  printf("using main took: %f milli seconds\n", t_s * 1000);
  return 0;
}
