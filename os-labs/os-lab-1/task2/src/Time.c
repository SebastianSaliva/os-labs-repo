#include "Time.h"  // Include the header file for the structure and function prototype

// Implement the function to modify a Time structure
void ChangeTime(struct Time *t, int h, int m, int s) {
  t->hours = h;
  t->minutes = m;
  t->seconds = s;
}
