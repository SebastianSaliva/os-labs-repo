#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

int main() {
  // pthread_create(&p_counting, &attr, Counting, (void*)&init_counter);
  // pthread_create(&p_print, NULL, PrintMessage, (void*)message);
  // pthread_attr_t attr;
  // pthread_attr_init(&attr);

  pthread_t p_receive;
  void* return_value;

  pthread_create(&p_receive, NULL, ReceiveValue, NULL);
  pthread_join(p_receive, &return_value);

  float* received = (float*)return_value;

  if (*received == -2) {
    printf("Number greater than 100\n");
    exit(1);
  }

  float asinRes;

  asinRes = asinf(*received);

  printf("Arcsine of %f: %f\n", *received, asinRes);
  free(received);
  return 0;

  return 0;
}

// void* Counting(void* param) {
//   int* ptr_init_c = (int*)param;

//   for (int i = *ptr_init_c; i < 35; i++) {
//     printf("%d\n", i);
//     usleep(100000);
//   }
// }

// void* PrintMessage(void* param) {
//   // char* msg = (char*)param;

//   // while (1) {
//   //   printf("%s\n", msg);
//   //   usleep(200000);
//   // }
// }

// void* thread_function(void* arg) {
//   int* result = malloc(sizeof(int));
//   *result = 42;  // This is the value we want to return
//   return (void*)result;
// }