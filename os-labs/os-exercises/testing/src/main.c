
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

bool is_prime(int n) {
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}
int main() {
  FILE* file = fopen("data.txt", "w");

  for (int i = 0; i < 9999; i++) {
    char sn[100];
    snprintf(sn, 100, "%d", i);
    char* blct = lct(sn);
    uintmax_t dlct = binary_string_to_decimal(blct);
    // printf("%d : %s : %lu\n", i, blct, dlct);
    if (is_prime((int)dlct)) {
      char sn2[100];
      snprintf(sn2, 100, "%lu", dlct);

      char* blct2 = lct(sn2);
      uintmax_t dlct2 = binary_string_to_decimal(blct2);

      if (is_prime((int)dlct2)) {
        fprintf(file, "%d %lu\n", i, dlct2);
      }
    };
  }
  fclose(file);
  // for (uintmax_t i = 0; i < UINTMAX_MAX; i++) {
  //   printf("%lu: ", i);
  //   char* ib = umToBinary(i);
  //   printf("%s\n", ib);

  //   free(ib);
  // }

  return 0;
}

// char* vals =
// "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

// free(bin_i);
// printf("%u:", binary_string_to_decimal(intToBinary(i)));
// printf("%s\n",
// uintmax_to_string(binary_string_to_decimal(intToBinary(i))));
//   char* vals =
//   "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

//   char* keys[strlen(vals) * 2];
//   int i = 0;
//   for (i; i < strlen(vals); i++) {
//     char c = vals[i];

//     char* c_bin = u8ToBinary((uint8_t)c);
//     keys[i] = c_bin;
//     // printf("%s", c_bin);
//   }

//   for (i; i < strlen(vals) * 2; i++) {
//     char* c_bin = flipMSD(keys[i - strlen(vals)]);
//     keys[i] = c_bin;
//   }

//   // for (int i = 0; i < 124; i++) {
//   //   printf("%s\n", keys[i]);
//   // }

//   int counttotal = 0;
//   for (int i = 0; i < strlen(vals) * 2; i++) {
//     char c = vals[i];
//     char* c_bin = keys[i];
//     int count = 0;

//     for (int j = 0; j < strlen(vals); j++) {
//       char c2 = vals[j];
//       char* c_bin2 = invNMSD(u8ToBinary((uint8_t)c2));

//       if (!strcmp(c_bin2, c_bin)) {
//         if (!count) {
//           counttotal++;
//         }
//         count++;

//         printf("%s appears %d\n", (c_bin2), count);
//       }
//       free(c_bin2);
//     }
//     count = 0;
//   }
//   printf("%d\n", counttotal);
//   return 0;
// }
