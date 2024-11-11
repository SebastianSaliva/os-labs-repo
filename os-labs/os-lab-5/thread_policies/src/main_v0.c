#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

#include "functions_v0.h"
double deltas[5];  // each thread will save their end-time in index of their id
double start_time_secs;
int main() {
  int ffp1 = 80, rrp1 = 80, ffp2 = 20, rrp2 = 20;

  int ff_prios[3] = {0, ffp1, ffp2};
  int rr_prios[3] = {0, rrp1, rrp2};

  // skipping index 0 to make code below more readable
  int ff_ids[3] = {0, 1, 3};
  int rr_ids[3] = {0, 2, 4};

  pthread_t p_ff1, p_ff2, p_rr1, p_rr2;
  pthread_attr_t attr_ff1, attr_ff2, attr_rr1, attr_rr2;

  // make attributes
  attr_ff1 = MakeAttr(ff_ids[1], ff_prios[1], SCHED_FIFO);
  attr_rr1 = MakeAttr(rr_ids[1], rr_prios[1], SCHED_RR);
  attr_ff2 = MakeAttr(ff_ids[2], ff_prios[2], SCHED_FIFO);
  attr_rr2 = MakeAttr(rr_ids[2], rr_prios[2], SCHED_RR);

  // Set start time
  struct timeval tv;
  gettimeofday(&tv, NULL);
  start_time_secs = ((double)tv.tv_sec + (double)tv.tv_usec / 1000000);

  // create the threads
  pthread_create(&p_ff1, &attr_ff1, ThreadFunction, &ff_ids[1]);
  pthread_create(&p_rr1, &attr_rr1, ThreadFunction, &rr_ids[1]);
  pthread_create(&p_ff2, &attr_ff2, ThreadFunction, &ff_ids[2]);
  pthread_create(&p_rr2, &attr_rr2, ThreadFunction, &rr_ids[2]);

  printf("All threads launched, this may take a bit...\n");
  // wait for threads
  pthread_join(p_ff1, NULL);
  pthread_join(p_rr1, NULL);
  pthread_join(p_ff2, NULL);
  pthread_join(p_rr2, NULL);

  // calculate deltas
  double delta_ff1, delta_ff2, delta_rr1, delta_rr2;
  double ff_deltas[3] = {0, deltas[ff_ids[1]], deltas[ff_ids[2]]};
  double rr_deltas[3] = {0, deltas[rr_ids[1]], deltas[rr_ids[2]]};

  printf("All Threads Done!\n");
  printf("T ; Policy ; Priority ; Delta \n");
  printf("%d ; FF     ; %d      ; %lf\n", ff_ids[1], ff_prios[1], ff_deltas[1]);
  printf("%d ; RR     ; %d      ; %lf\n", rr_ids[1], rr_prios[1], rr_deltas[1]);
  printf("%d ; FF     ; %d      ; %lf\n", ff_ids[2], ff_prios[2], ff_deltas[2]);
  printf("%d ; RR     ; %d      ; %lf\n", rr_ids[2], rr_prios[2], rr_deltas[2]);
  // destroy attributes
  pthread_attr_destroy(&attr_ff1);
  pthread_attr_destroy(&attr_rr1);
  pthread_attr_destroy(&attr_ff2);
  pthread_attr_destroy(&attr_rr2);

  return 0;
}
