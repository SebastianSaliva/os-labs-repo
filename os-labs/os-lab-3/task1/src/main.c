#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

typedef struct thread_data {
  int a;
  int quit;
  int result;

} thread_data;

int main() {
  pthread_t p_receive;
  void* return_value;

  pthread_create(&p_receive, NULL, ReceiveValue, NULL);

  thread_data vals = {0, 0, -1};




  while (!((0 <= vals.result) && (vals.result <= 1)) && !vals.quit) {

  }
  if (vals.quit){
        printf("Number greater than 100\n");
    exit(1);
  }


  float* received = (float*)return_value;
  pthread_join(p_receive, NULL);


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