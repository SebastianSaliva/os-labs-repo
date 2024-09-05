#include "functions.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENH 4
#define LENW 20

/**
 * @brief aligns all strings in text to the left
 *
 * @param[in] text double pointer containing all strings
 *
 */
void left(char **text) { prep(text); }

/**
 * @brief aligns all strings in text to the right
 *
 * @param[in] text double pointer containing all strings
 *
 */
void right(char **text) {
  prep(text);

  for (int l = 0; l < LENH; l++) {
    int linelen = strlen(text[l]);

    int diff = LENW - linelen;
    if (diff) {
      char *out = (char *)malloc(LENW * sizeof(char));
      int i;
      for (i = 0; i < diff; i++) {
        out[i] = ' ';
      }
      int j = 0;
      for (i; i < LENW; i++) {
        out[i] = text[l][j];
        j++;
      }
      out[i] = '\0';
      text[l] = out;
    }
  }
}

/**
 * @brief justifies all strings in text
 *
 * @param[in] text double pointer containing all strings
 *
 */
void justify(char **text) {
  prep(text);

  for (int l = 0; l < LENH; l++) {
    int linelen = strlen(text[l]);

    int diff = LENW - linelen;

    if (diff) {
      char *out = (char *)malloc(LENW * sizeof(char));

      int wordCount = 1;
      int spaces = 0;

      for (int i = 0; i < linelen; i++) {
        if (text[l][i] == ' ') {
          wordCount++;
          spaces++;
        }
      }
      int spacesperspace = 1;
      if (wordCount == 1) {
      } else {
        spacesperspace = diff / spaces + 1;

        int j = 0;
        int i = 0;
        int firstSp = 1;
        for (i = 0; i < linelen; i++) {
          if (text[l][i] == ' ') {
            int k = 0;
            int odd = 0;
            if (diff % 2 == 1 && firstSp == 1) {
              odd = 1;
              firstSp = 0;
              if (wordCount == 2) {
                odd = 0;
              }
            }
            for (k = 0; k < spacesperspace + odd; k++) {
              out[j + k] = ' ';
            }
            j += k;
          } else {
            out[j] = text[l][i];
            j++;
          }
          out[j] = '\0';
        }
        text[l] = out;
      }
    }
  }
}
/**
 * @brief removes leading and trailing spaces and leaves only 1 space between
 * words, for all strings in text
 *
 * @param[in] text double pointer containing all strings
 *
 */
void prep(char **text) {
  for (int l = 0; l < LENH; l++) {
    int i = 0;
    int prevwasspace = 0;

    char *out = (char *)malloc(LENW * sizeof(char));
    int offset = 0;
    while (isspace(text[l][i])) {
      i++;
      offset++;
    }

    while (text[l][i] != '\0') {
      if (!isspace(text[l][i])) {
        out[i - offset] = text[l][i];
        prevwasspace = 0;
      } else {
        if (prevwasspace) {
          offset++;
        } else {
          prevwasspace = 1;
          out[i - offset] = text[l][i];
        }
      }
      i++;
    }
    out[i - offset - 1] = '\0';

    text[l] = out;
  }
}
