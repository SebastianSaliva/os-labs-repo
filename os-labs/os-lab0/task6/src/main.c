#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define LENH 4
#define LENW 20
int main() {
  printf("Welcome! Max lines: %d, Max chars per line: %d.\n", LENH, LENW);

  for (int i = 0; i < LENW; i++) {
    printf("#");
  }
  printf("\n");

  char **text = (char **)malloc(LENH * sizeof(char *));
  for (int i = 0; i < LENH; i++) {
    text[i] = (char *)malloc(LENW * sizeof(char));
  }

  for (int i = 0; i < LENH; i++) {
    fgets(text[i], LENW + 2, stdin);
  }

  printf("Text menu\n");
  printf("1 - align left.\n");
  printf("2 - align right.\n");
  printf("3 - justify.\n");

  int code;
  printf("Enter Number: ");
  scanf("%d", &code);

  if (code == 1) {
    left(text);
  } else if (code == 2) {
    right(text);
  } else if (code == 3) {
    justify(text);
  } else {
    printf("Invalid code.");
  }

  for (int i = 0; i < LENW; i++) {
    printf("#");
  }
  printf("\n");

  for (int i = 0; i < LENH; i++) {
    printf("%s \n", text[i]);
  }
}
