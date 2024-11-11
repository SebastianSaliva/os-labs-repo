#ifndef TASK3_FUNCTIONS_H
#define TASK3_FUNCTIONS_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* u8ToBinary(uint8_t n);
char* u16ToBinary(uint16_t n);
char* u32ToBinary(uint32_t n);
char* intToBinary(int n);
char* uintToBinary(unsigned int num);
char* umToBinary(uintmax_t num);
char* inv(char* bin_str);
char* rev(char* str);
char* flipMSD(char* bin_str);

char* lct(char* decimal_str);

uintmax_t binary_string_to_decimal(char* binary_string);
char* uintmax_to_string(uintmax_t value);
char* trimL0(char* binary_string);
char* trimLd(char* binary_string);
char* trimL10(char* binary_string);
#endif  // TASK3_FUNCTIONS_H