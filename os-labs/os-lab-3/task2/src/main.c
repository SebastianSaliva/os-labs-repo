#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

double x[1000000];

int main() {
  for (int i = 0; i < 1000000; i++) {
    x[i] = tan(i + 1);
  }
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
  void* seg0return;
  void* seg1return;
  void* seg2return;
  void* seg3return;
  void* seg4return;
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

  pthread_join(p_segment0, &seg0return);
  seg0sum = (double*)seg0return;
  total_sum += *seg0sum;
  pthread_join(p_segment1, &seg1return);
  seg1sum = (double*)seg1return;
  total_sum += *seg1sum;
  pthread_join(p_segment2, &seg2return);
  seg2sum = (double*)seg2return;
  total_sum += *seg2sum;
  pthread_join(p_segment3, &seg3return);
  seg3sum = (double*)seg3return;
  total_sum += *seg3sum;
  pthread_join(p_segment4, &seg4return);
  seg4sum = (double*)seg4return;
  total_sum += *seg4sum;

  printf("Result: %lf\n", total_sum);

  double tan_arr[1000000];

  for (int i = 0; i < 1000000; i++) {
    tan_arr[i] = tan(i + 1);
  }
  double sum = 0;
  for (int i = 0; i < 1000000; i++) {
    sum += tan_arr[i];
  }
  printf("Result: %lf\n", sum);
  return 0;
}
