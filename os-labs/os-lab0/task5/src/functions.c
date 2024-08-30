#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintTest() { printf("Test\n"); }

void NumToStr(int num) {
  char *digitInText[] = {"zero ", "one ", "two ",   "three ", "four ",
                         "five ", "six ", "seven ", "eight ", "nine "};

  int numCopy = 0;
  numCopy += num;

  int rnum = 0;
  int digitCount = 0;

  if (num == 0) {
    char *str = "zero ";
  } else {
    // get amount of digits
    while (num != 0) {
      num /= 10;
      digitCount++;
    }

    int i = 1;
    while (numCopy != 0) {
      rnum += (numCopy % 10) * (power(10, digitCount - i));
      numCopy /= 10;
      i++;
    }

    char *str = (char *)malloc(digitCount * sizeof(char));

    i = 0;

    int k;
    for (k = 0; k < digitCount; k++) {
      int digit = rnum % 10;

      char *digitT = digitInText[digit];
      int j;
      for (j = 0; j < strlen(digitT); j++) {
        str[i + j] = digitT[j];
      }
      i += j;
      rnum /= 10;
    }

    printf("%s", str);
  }
}

int power(int base, int exp) {
  int i, result = 1;
  for (i = 0; i < exp; i++) result *= base;
  return result;
}