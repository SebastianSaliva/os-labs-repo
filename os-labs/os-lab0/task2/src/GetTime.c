#include "GetTime.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetTime(struct Time *t) {
  int invalid = 1;

  while (invalid) {
    invalid = 0;
    char CurrentTime[9];

    printf("Current time (hh:mm:ss): ");

    scanf("%8s", CurrentTime);

    if (CurrentTime[5] != ':' || CurrentTime[2] != ':') {
      invalid = 1;
    }
    if (strlen(CurrentTime) != 8) {
      invalid = 1;
    }
    CurrentTime[2] = '0' + 1;
    CurrentTime[5] = '0' + 1;

    for (int i = 0; i < strlen(CurrentTime); i++) {
      if (!isdigit(CurrentTime[i])) {
        invalid = 1;
      }
    }

    char buffer[3];
    buffer[0] = CurrentTime[0];
    buffer[1] = CurrentTime[1];

    int hours = atoi(buffer);

    buffer[0] = CurrentTime[3];
    buffer[1] = CurrentTime[4];

    int minutes = atoi(buffer);

    buffer[0] = CurrentTime[6];
    buffer[1] = CurrentTime[7];

    int seconds = atoi(buffer);

    if (hours > 23 || minutes > 59 || seconds > 59) {
      invalid = 1;
    }
    if (invalid) {
      printf("Invalid format!\n");

    } else {
      ChangeTime(t, hours, minutes, seconds);
      invalid = 0;
    }
  }
}
