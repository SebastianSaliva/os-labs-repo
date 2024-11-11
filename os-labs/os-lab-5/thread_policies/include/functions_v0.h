#ifndef TASK3_FUNCTIONS_H
#define TASK3_FUNCTIONS_H
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

void* ThreadFunction(void* arg);
pthread_attr_t MakeAttr(int id, int priority, int sched_policy);
#endif  // TASK3_FUNCTIONS_H