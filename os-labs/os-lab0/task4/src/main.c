#include <stdio.h>

#include "functions.h"

#define MAX_LENGTH 100

int main() {
  PrintTest();

  char src[] = "hola mundo";
  char target = 'o';
  char put[] = "ronda";
  char dst[MAX_LENGTH];

  Insert(src, dst, target, put);
  printf("%s\n", dst);

  return 0;
}
