#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

#include "functions_v0.h"

#define ENABLE_INDIVIDUAL_PRIORITY_ARGUMENTATION_STYLE 0
double start_time_secs;
double deltas[5];  // each thread will save their end-time in index of their id

// so that all threads start the cpu_bound simulation equally, we signal
unsigned char start_cpu_bound = 0;
unsigned char threads_not_ready = 4;

int main(int argc, char* argv[]) {
  // for convinience, since ids start at 1, we will start our indexing at 1
  int ff_ids[3] = {0, 1, 3};
  int rr_ids[3] = {0, 2, 4};

  int priorities[6][5] = {
      {0, 50, 50, 50, 50},  // E0
      {0, 01, 01, 99, 99},  // E1
      {0, 99, 99, 01, 01},  // E2
      {0, 90, 10, 90, 10},  // E3
      {0, 20, 20, 80, 80},  // E4
      {0, 80, 80, 20, 20}   // E5
  };

  int ffp1, rrp1, ffp2, rrp2;  // declared here in case of individual args

  unsigned char ecase = 0b000;  // using 8bits to test case
  if (argc == 1) {
    printf("No args provided\n");
    printf("Using baseline, equivalent to ./<task> E0\n");
    printf("Note: if you see this and nothing else run with sudo!\n");
    ecase = 0b000;
  } else if (argc == 2) {  // Arg provided should be EN where N is 0 to 5
    ecase = 0b111;  // starting val, if this stays the same, the arg was invalid
    char n = argv[1][1];
    if (n == '0') ecase = 0b000;
    if (n == '1') ecase = 0b001;
    if (n == '2') ecase = 0b010;
    if (n == '3') ecase = 0b011;
    if (n == '4') ecase = 0b100;
    if (n == '5') ecase = 0b101;
    if (argv[1][0] != 'E') ecase = 0b111;
    if (ecase == 0b111) {  // check it stayed the same
      printf("Invalid arg provided.\nValid args are: E0 E1 E2 E3 E4 E5\n");
      return 1;
    }
    // turn this on to enable argumenting individually
  } else if (argc == 5 && ENABLE_INDIVIDUAL_PRIORITY_ARGUMENTATION_STYLE) {
    if (GetPriosOpt(argv, &ffp1, &rrp1, &ffp2, &rrp2)) {
      printf("Error in args\n");
      return 1;
    };
  } else {
    printf("Invalid amount of parameters\nrun ./<task> E0\n");
    return 1;
  }

  ffp1 = priorities[ecase][ff_ids[1]];
  rrp1 = priorities[ecase][rr_ids[1]];
  ffp2 = priorities[ecase][ff_ids[2]];
  rrp2 = priorities[ecase][rr_ids[2]];

  int ff_prios[3] = {0, ffp1, ffp2};
  int rr_prios[3] = {0, rrp1, rrp2};

  pthread_t p_ff1, p_ff2, p_rr1, p_rr2;
  pthread_attr_t attr_ff1, attr_ff2, attr_rr1, attr_rr2;

  // make attributes
  attr_ff1 = MakeAttr(ff_ids[1], ff_prios[1], SCHED_FIFO);
  attr_rr1 = MakeAttr(rr_ids[1], rr_prios[1], SCHED_RR);
  attr_ff2 = MakeAttr(ff_ids[2], ff_prios[2], SCHED_FIFO);
  attr_rr2 = MakeAttr(rr_ids[2], rr_prios[2], SCHED_RR);

  // create the threads
  pthread_create(&p_ff1, &attr_ff1, ThreadFunction, &ff_ids[1]);
  pthread_create(&p_rr1, &attr_rr1, ThreadFunction, &rr_ids[1]);
  pthread_create(&p_ff2, &attr_ff2, ThreadFunction, &ff_ids[2]);
  pthread_create(&p_rr2, &attr_rr2, ThreadFunction, &rr_ids[2]);

  // Set start time after making threads; since cpu_bound simulation doesn't
  // start till indicated
  struct timeval tv;
  gettimeofday(&tv, NULL);
  start_time_secs = ((double)tv.tv_sec + (double)tv.tv_usec / 1000000);

  while (threads_not_ready)  // decreaments each time a thread is ready
    usleep(100);

  start_cpu_bound = 1;  // race starts

  printf("All threads racing, this may take a bit...\n");

  // wait for threads to finish
  pthread_join(p_ff1, NULL);
  pthread_join(p_rr1, NULL);
  pthread_join(p_ff2, NULL);
  pthread_join(p_rr2, NULL);

  // deltas is a global array
  // where each thread should save the end time indexed at its id
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