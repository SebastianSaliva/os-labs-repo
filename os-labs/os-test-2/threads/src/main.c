#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "functions.h"

void* ThreadFunc() {
  printf("Hello from simple thread\n");
  sleep(1);
  printf("simple thread finished\n");
  return NULL;
}

void* ThreadFuncArg(void* arg) {
  int* arg_int = (int*)arg;
  printf("Hello from argumented thread with argument %d\n", *arg_int);
  sleep(1);
  printf("argumented thread finished\n");
  return NULL;
}
void* ThreadFuncRet() {
  int* ret = malloc(sizeof(int));
  *ret = 42;
  printf("Hello from returning thread returning %d\n", *ret);
  sleep(1);
  printf("returning thread finished\n");
  return (void*)ret;
}
void* ThreadFuncArgRet(void* arg) {
  int* arg_int = (int*)arg;
  int* ret = malloc(sizeof(int));
  *ret = *arg_int * 2;
  printf(
      "Hello from argumented returning thread with argument %d returning %d\n",
      *arg_int, *ret);
  sleep(1);
  printf("argumented returning thread finished\n");
  return (void*)ret;
}

int main() {
  // SIMPLE THREAD
  pthread_t p_thread;
  pthread_create(&p_thread, NULL, ThreadFunc, NULL);
  pthread_join(p_thread, NULL);  // wait for thread to finish
  printf("ThreadFunc done.\n");
  // ARGUMENTED THREAD
  pthread_t p_thread_arg;
  int arg = 1;
  pthread_create(&p_thread_arg, NULL, ThreadFuncArg, (void*)&arg);
  pthread_join(p_thread_arg, NULL);  // waith for thread to finish
  printf("ThreadFunc done.\n");

  // THREAD WITH RETURN VALUE
  pthread_t p_thread_ret;
  int* ret;
  pthread_create(&p_thread_ret, NULL, ThreadFuncRet, NULL);
  pthread_join(p_thread_ret, (void**)&ret);
  printf("ThreadFuncRet returned %d\n", *ret);
  free(ret);

  // ARGUMENTED THREAD WITH RETURN VALUE
  pthread_t p_thread_arg_ret;
  int arg_ar = 42;
  int* ret_ar;
  pthread_create(&p_thread_arg_ret, NULL, ThreadFuncArgRet, (void*)&arg_ar);
  pthread_join(p_thread_arg_ret, (void**)&ret_ar);
  printf("ThreadFuncArgRet returned %d\n", *ret_ar);
  free(ret_ar);

  return 0;
}
