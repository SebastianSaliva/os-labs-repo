#ifndef TASK_FUNCTIONS_H
#define TASK_FUNCTIONS_H
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

void* ThreadFunction(void* arg);
pthread_attr_t MakeAttr(int id, int priority, int sched_policy);
int GetPriosOpt(char** argv, int* ffp1, int* rrp1, int* ffp2, int* rrp2);
#endif  // TASK_FUNCTIONS_H