#include "GetTime.h"
#include "PrintTime.h"
#include "Time.h"

int main() {
  struct Time time1 = {1, 2, 4};

  PrintTime(time1);

  GetTime(&time1);

  PrintTime(time1);

  return 0;
}
