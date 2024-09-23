#include "functions.h"

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* ReceiveValue(void* param) {
  int* ptr_init_c = (int*)param;

  while (1) {
    float num;
    printf("Enter number between 0 and 1: ");
    scanf("%f", &num);
    if (0 <= num && num <= 1) {
      float* result = malloc(sizeof(float));
      *result = num;
      return (void*)result;

    } else {
      if (num > 100) {
        //-2
        float* result = malloc(sizeof(float));
        *result = -2;
        return (void*)result;
      }

      printf("Invalid Number\n");
    }
  }
}
