#include "PrintTime.h"

#include <stdio.h>
#include <string.h>

void PrintTime(struct Time t) {
  char hrs[3];
  char min[3];
  char sec[3];

  if (t.hours <= 9) {
    sprintf(hrs, "0%d", t.hours);
  } else {
    sprintf(hrs, "%d", t.hours);
  }
  if (t.minutes <= 9) {
    sprintf(min, "0%d", t.minutes);
  } else {
    sprintf(min, "%d", t.minutes);
  }
  if (t.seconds <= 9) {
    sprintf(sec, "0%d", t.seconds);
  } else {
    sprintf(sec, "%d", t.seconds);
  }
  printf("%s:%s:%s\n", hrs, min, sec);
  return;
}
