#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief replaces instances of find found in src with the replacement string
 * and stores it in dst
 *
 * This functions checks whether the guess equals the target,
 * returns 0 if so, 1 if the guess is larger than target, or -1 if smaller
 *
 * @param[in] src original string
 * @param[in] dst destination to save modified string
 * @param[in] find character to replace
 * @param[in] replacement character to use as replacement
 *
 *
 */

void Replace(char* src, char* dst, char find, char replacement) {
  // int i;
  for (int i = 0; i < strlen(src); i++) {
    if (src[i] == find) {
      dst[i] = replacement;
    } else {
      dst[i] = src[i];
    }
  }
  // dst[i] = '\0';
  return;
}

/**
 * @brief Checks whether two numbers are equal.
 *
 * This functions checks whether the guess equals the target,
 * returns 0 if so, 1 if the guess is larger than target, or -1 if smaller
 *
 * @param[in] target Number to guess.
 * @param[in] guess Number guessed.
 * @return 0 if equals else sign of target - guess
 *
 * @note This function does not handle overflow.
 *
 * @example
 * int result = VerifyGuess(5, 5);
 * // result now holds the value 0
 */

/**
 * @brief inserts ins after each instance of find found in src and stores it in
 * dst
 *
 * @param[in] src original string
 * @param[in] dst destination to save modified string
 * @param[in] find character to find
 * @param[in] ins characters to insert
 *
 *
 */

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
