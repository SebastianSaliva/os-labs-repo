
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fptr;

  fptr = fopen("binary.dat", "rb");

  // // checking if the file is opened successfully
  // if (fptr == NULL) {
  //   printf(
  //       "The file is not opened. The program will "
  //       "now exit.");
  //   exit(0);
  // }

  // int number = 3248679;

  // fwrite(&number, sizeof(int), 1, fptr);

  // double my_double = 8.3542345677889;

  // fwrite(&my_double, sizeof(double), 1, fptr);

  // char* text = "hello bin";

  // fwrite(text, sizeof(char), 10, fptr);

  int x_read;
  fread(&x_read, sizeof(int), 1, fptr);

  printf("The first int is %d\n", x_read);

  return 0;
}
