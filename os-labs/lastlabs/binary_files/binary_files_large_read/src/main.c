// C Program to illustrate file opening
#include <stdio.h>
#include <stdlib.h>

#define N_NUMBERS 200000
#define PI 3.141592

int main() {
  FILE *fptr, *fptr2;

  float numbers[N_NUMBERS];

  // lleno el arreglo
  for (int i = 0; i < N_NUMBERS; i++) {
    numbers[i] = i * PI;
  }

  /////// leo del archivo de texto plano
  fptr2 = fopen("text_data.txt", "r");
  float curr_num;
  for (int i = 0; i < N_NUMBERS; i++) {
    fscanf(fptr2, "%f", &curr_num);
    if (i < 30) {
      printf("%f\n", curr_num);
    }
  }

  /////// leo del archivo binario
  // fptr = fopen("binary.dat", "rb");
  // fread(&numbers, sizeof(float), N_NUMBERS, fptr);

  // for (int i = 0; i < 30; i++) {
  //   printf("%f\n", numbers[i]);
  // }

  return 0;
}
