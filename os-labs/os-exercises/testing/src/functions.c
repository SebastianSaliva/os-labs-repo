#include "functions.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* u8ToBinary(uint8_t n) {}
char* u16ToBinary(uint16_t n) {}
char* u32ToBinary(uint32_t num) {}
char* intToBinary(int n) {}
char* uintToBinary(unsigned int num) {
  if (num == 0) {
    char* result = malloc(2 * sizeof(char));
    if (result == NULL) {
      return NULL;  // Memory allocation failed
    }
    strcpy(result, "0");
    return result;
  }

  int bits = sizeof(unsigned int) * 8;
  char* binary = malloc((bits + 1) * sizeof(char));
  if (binary == NULL) {
    return NULL;  // Memory allocation failed
  }

  binary[bits] = '\0';  // Null-terminate the string

  for (int i = bits - 1; i >= 0; i--) {
    binary[i] = (num & 1) ? '1' : '0';
    num >>= 1;
  }

  // Find the first '1' to remove leading zeros
  char* result = binary;
  while (*result == '0') {
    result++;
  }

  // Create a new string without leading zeros
  char* final_result = strdup(result);
  free(binary);

  return final_result;
}
char* umToBinary(uintmax_t num) {
  if (num == 0) {
    char* result = malloc(2 * sizeof(char));
    if (result == NULL) {
      return NULL;  // Memory allocation failed
    }
    strcpy(result, "0");
    return result;
  }

  int bits = sizeof(uintmax_t) * 8;
  char* binary = malloc((bits + 1) * sizeof(char));
  if (binary == NULL) {
    return NULL;  // Memory allocation failed
  }

  binary[bits] = '\0';  // Null-terminate the string

  for (int i = bits - 1; i >= 0; i--) {
    binary[i] = (num & 1) ? '1' : '0';
    num >>= 1;
  }

  // Find the first '1' to remove leading zeros
  char* result = binary;
  while (*result == '0') {
    result++;
  }

  // Create a new string without leading zeros
  char* final_result = strdup(result);
  free(binary);

  return final_result;
}

char* lct(char* decimal_str) {
  int worst_len = strlen(decimal_str) * 4;
  char* bin_s = (char*)malloc((worst_len + 1) * sizeof(char));
  int bi = 0;
  for (int i = 0; i < strlen(decimal_str); i++) {
    char c = decimal_str[i];

    if (c == '0') {
      bin_s[bi] = '0';
      bi++;
    } else if (c == '1') {
      bin_s[bi] = '1';
      bi++;
    } else if (c == '2') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '0';
      bi++;
    } else if (c == '3') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '1';
      bi++;
    } else if (c == '4') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '0';
      bi++;
      bin_s[bi] = '0';
      bi++;
    } else if (c == '5') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '0';
      bi++;
      bin_s[bi] = '1';
      bi++;
    } else if (c == '6') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '0';
      bi++;
    } else if (c == '7') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '1';
      bi++;
    } else if (c == '8') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '0';
      bi++;
      bin_s[bi] = '0';
      bi++;
      bin_s[bi] = '0';
      bi++;
    } else if (c == '9') {
      bin_s[bi] = '1';
      bi++;
      bin_s[bi] = '0';
      bi++;
      bin_s[bi] = '0';
      bi++;
      bin_s[bi] = '1';
      bi++;
    }
  }
  bin_s[bi] = '\0';
  return bin_s;
}

// char* lct(char* bin_s) {
//   uintmax_t d_n = binary_string_to_decimal(bin_s);
//   printf("%u\n", d_n);
//   char* d_n_s = uintmax_to_string(d_n);
//   printf("%s\n", d_n_s);
//   // for (int i = 0; i < strlen(bin_s);i++){

//   // }
// }

uintmax_t binary_string_to_decimal(char* binary_string) {
  uintmax_t result = 0;
  size_t len = strlen(binary_string);

  for (size_t i = 0; i < len; i++) {
    if (binary_string[i] == '1') {
      result = (result << 1) | 1;
    } else if (binary_string[i] == '0') {
      result = result << 1;
    } else {
      // Invalid character in the binary string
      fprintf(stderr, "Error: Invalid character in binary string\n");
      return 0;
    }
  }

  return result;
}

char* uintmax_to_string(uintmax_t value) {
  // Allocate enough space for the maximum possible uintmax_t value
  // (20 digits for 64-bit uintmax_t) plus null terminator
  char* result = malloc(21 * sizeof(char));
  if (result == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  // Convert the value to string
  snprintf(result, 21, "%ju", value);

  return result;
}
char* rev(char* str) {
  if (str == NULL) return NULL;
  size_t len = strlen(str);
  char* reversed = (char*)malloc((len + 1) * sizeof(char));
  if (reversed == NULL) return NULL;
  for (size_t i = 0; i < len; i++) reversed[i] = str[len - 1 - i];
  reversed[len] = '\0';
  return reversed;
}

char* u8ToBinaryPrint(uint8_t n) {
  char* str = u8ToBinary(n);
  printf("%s\n", str);
  return str;
};
char* u32ToBinaryPrint(uint8_t n) {
  char* str = u32ToBinary(n);
  printf("%s\n", str);
  return str;
};
char* intToBinaryPrint(int n) {
  char* str = intToBinary(n);
  printf("%s\n", str);
  return str;
};
char* trimL0(char* binary_string) {
  int offset = 0;
  for (int i = 0; i < 32; i++) {
    if (binary_string[i] == '1') break;
    offset++;
  }
  if (!offset) return binary_string;

  char b_s[32 + 1];
  b_s[33] = '\0';

  int len = strlen(binary_string);
  if (len != 32) {
    int o = 0;
    while (len < 32) {
      b_s[o] = '0';
      o++;
      len++;
    }
    offset += o;
    for (int i = 0; i < 32; i++) {
      b_s[o + i] = binary_string[i];
    }
  }

  char str_to_use[33];
  if (strlen(binary_string) != 32) {
    strcpy(str_to_use, b_s);
  } else {
    strcpy(str_to_use, binary_string);
  }

  static char trimmed[32 + 1];
  trimmed[32 - offset] = '\0';
  for (int i = 0; i < 32 - offset; i++) trimmed[i] = str_to_use[i + offset];

  return trimmed;
}

char* trimLd(char* binary_string) {
  char* trimmed = (char*)malloc(strlen(binary_string) * sizeof(char));
  trimmed[strlen(binary_string) - 1] = '\0';
  for (int i = 0; i < strlen(binary_string); i++)
    trimmed[i] = binary_string[i + 1];

  return trimmed;
}

char* trimL10(char* binary_string) {
  static char trimmed[8 + 1];
  trimmed[8 - 1] = '\0';
  for (int i = 0; i < 8; i++) trimmed[i] = binary_string[i + 1];

  return trimmed;
}

char* inv(char* bin_str) {
  char* inv_bin_str = (char*)(malloc(strlen(bin_str + 1) * sizeof(char)));
  inv_bin_str[strlen(bin_str)] = '\0';

  for (int i = 0; i < strlen(bin_str); i++) {
    inv_bin_str[i] = (bin_str[i] == '0') ? '1' : '0';
  }
  // printf("%s", inv_bin_str);
  return inv_bin_str;
}

char* flipMSD(char* bin_str) {
  char* flipped = (char*)malloc(strlen(bin_str) * sizeof(char));
  strcpy(flipped, bin_str);
  flipped[0] = (flipped[0] == '0') ? '1' : '0';
  return flipped;
}
