#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintTest() { printf("Test\n"); }

void Replace(char* src, char* dst, char find, char replacement) {
  int i;
  for (int i = 0; i < strlen(src); i++) {
    if (src[i] == find) {
      dst[i] == replacement;
    } else {
      dst[i] = src[i];
    }
  }
  // dst[i] = '\0';
  return;
}

void Insert(char* src, char* dst, char find, char* ins) {
  int src_len = strlen(src);
  int ins_len = strlen(ins);
  int occuranceIndexes[src_len];
  int occuranceCount = 0;

  for (int i = 0; i < src_len; i++) {
    if (find == src[i]) {
      occuranceIndexes[occuranceCount] = i;
      occuranceCount++;
    }
  }
  int offset = 0;
  int occId = 0;
  for (int i = 0; i < ins_len * occuranceCount + src_len; i++) {
    dst[i] = src[i - offset];

    if (i - offset == occuranceIndexes[occId]) {
      int j = 0;
      for (j = 0; j < ins_len; j++) {
        dst[i + 1 + j] = ins[j];
      }
      i += j;
      offset += j;
      occId++;
    }
  }
}
