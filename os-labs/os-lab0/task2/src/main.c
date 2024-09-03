#include "GetTime.h"
#include "PrintTime.h"
#include "Time.h"

int main() {
  struct Time time1 = {15, 5, 32};

  PrintTime(time1);

  GetTime(&time1);

  PrintTime(time1);

  return 0;
}
