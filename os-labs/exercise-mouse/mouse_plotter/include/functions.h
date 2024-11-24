#ifndef MOUSEPLOTTER_FUNCTIONS_H
#define MOUSEPLOTTER_FUNCTIONS_H

void ReadCoordSet(int signum);
void *BinaryFileReader();
int ReadIntFromBinFile();
void SetUpTimers();
void IntSigHandler(int signum);

#endif  // MOUSEPLOTTER_FUNCTIONS_H