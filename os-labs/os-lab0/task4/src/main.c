#include <stdio.h>

#include "functions.h"

#define MAX_LENGTH 100

int main() {
  char src[] = "hola mundo";
  char target = 'o';
  char put[] = "ronda";
  char put2 = 'a';
  char dst[MAX_LENGTH];
  // Replace(src, dst, target, put2);
  Insert(src, dst, target, put);
  printf("%s\n", dst);

  return 0;
}
