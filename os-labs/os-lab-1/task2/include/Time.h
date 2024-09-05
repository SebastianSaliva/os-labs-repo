#ifndef TIME_H  // Include guard to prevent multiple inclusions
#define TIME_H

// Define a structure called 'Person'
struct Time {
  int hours;
  int minutes;
  int seconds;
};

// Function prototype for time
void ChangeTime(struct Time *t, int h, int m, int s);

#endif  // TIME_H