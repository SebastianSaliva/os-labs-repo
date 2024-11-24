#ifndef MOUSESAVER_FUNCTIONS_H
#define MOUSESAVER_FUNCTIONS_H

#include <stdint.h>

void* MouseReaderThread();
void AddDeltasToAbsPos(int8_t x_delta, int8_t y_delta);
void AbsPosToTermCoords(float* term_coords);
int ConvertCoordsToIntFormat(float* term_coords);
void signal_handler(int signum);

#endif  // MOUSESAVER_FUNCTIONS_H
