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

  // escribo el archivo
  // fptr = fopen("binary.dat", "wb");
  // fwrite(numbers, sizeof(float), N_NUMBERS, fptr);

  fptr2 = fopen("text_data.txt", "w");
  for (int i = 0; i < N_NUMBERS; i++) {
    fprintf(fptr2, "%f\n", numbers[i]);
  }

  return 0;
}
