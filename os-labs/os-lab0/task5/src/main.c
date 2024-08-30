#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main() {
  int number = 0;

  printf("Input Int:");
  scanf("%d", &number);

  NumToStr(number);
  return 0;
}
