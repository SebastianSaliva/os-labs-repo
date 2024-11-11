#include "functions_v0.h"

#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

#define LOOP_AMOUNT 200

extern double start_time_secs;
extern double deltas[5];
int thread_not_done = 4;
/// @brief runs a cpu bound function LOOP_AMOUNT times, the calculates the time
/// delta from when the it is done looping and the start of the parent process
/// @param arg takes in an int used as the id of the thread, not a pid
/// @return NULL -deltas are saved to global deltas array, indexed at their id
void* ThreadFunction(void* arg) {
  printf("T is running\n");  // const str to reduce cpu consumption
  int count = 0;
  while (count < LOOP_AMOUNT) {
    for (volatile long i = 0; i < 1000000000; i++);
    // printf("T:%d Iteration: %d\n", id, i); // optional print
    count++;
  }

  // get delta
  struct timeval tv_end;
  gettimeofday(&tv_end, NULL);
  double time_delta =
      ((double)tv_end.tv_sec + (double)tv_end.tv_usec / 1000000) -
      start_time_secs;

  // after getting delta, sleep till other threads are done
  // such that their delta is not greatly affected by the printing
  thread_not_done--;
  while (thread_not_done) usleep(5000000);
  // yes it makes the program slower but provides better accuracy

  // then print all info of thread
  int id = *(int*)arg;
  int policy;
  struct sched_param param;
  // get sched param is pulled from attr of thread
  int thread_param_err = pthread_getschedparam(pthread_self(), &policy, &param);

  if (thread_param_err)  // check if getting the param was faulty
    printf("Error getting thread parameters: %s\n", strerror(thread_param_err));

  const char* policy_str = (policy == SCHED_FIFO)    ? "SCHED_FIFO"
                           : (policy == SCHED_RR)    ? "SCHED_RR"
                           : (policy == SCHED_OTHER) ? "SCHED_OTHER"
                                                     : "UNKNOWN";

  printf("T:%d (priority: %d) (policy: %s) ended. Delta: %lf\n", id,
         param.sched_priority, policy_str, time_delta);

  deltas[id] = time_delta;
  return NULL;
};

/// @brief creates and returns an attribute to be used for creating a thread
/// @param id - for error printing
/// @param priority - priority to set thread to 1-99
/// @param sched_policy -scheduling policy of thread 1-2
/// @return pthread_attr_t attribute to give to thread
pthread_attr_t MakeAttr(int id, int priority, int sched_policy) {
  struct sched_param param;
  pthread_attr_t attr;

  char* sched_string = (sched_policy == SCHED_FIFO)    ? "SCHED_FIFO"
                       : (sched_policy == SCHED_RR)    ? "SCHED_RR"
                       : (sched_policy == SCHED_OTHER) ? "SCHED_OTHER"
                                                       : "UNKNOWN";

  // set fifo 1
  // if 0 is not returned there was an error initializing attr
  if (pthread_attr_init(&attr)) {
    printf("Attr:%d-%s Error on attr init\n.", id, sched_string);
    exit(1);
  }

  // if 0 is not returned there was an error setting the sched policy of attr
  if (pthread_attr_setschedpolicy(&attr, sched_policy)) {
    printf("Attr:%d-%s Error setting sched pol to attr\n.", id, sched_string);
  }

  // Set to system scope - should help fix errors
  int ret = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  if (ret != 0) {
    printf("Attr:%d-%s Error setting scope: %s\n", id, sched_string,
           strerror(ret));
  }

  // Set explicit scheduling - should help fix errors
  ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
  if (ret != 0) {
    printf("Attr:%d-%s Error setting inherit sched: %s\n", id, sched_string,
           strerror(ret));
  }

  param.sched_priority = priority;
  // if 0 is not returned there was an error setting the sched param to attr
  if (pthread_attr_setschedparam(&attr, &param)) {
    printf("Attr:%d-%s Error setting sched param to attr\n.", id, sched_string);
    if (!priority)
      printf("if you see this, sorry use prio 1 instead of 0 idk lol\n");
  }

  return attr;
};