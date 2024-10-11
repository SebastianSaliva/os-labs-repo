#ifndef IMU_HANDLER_FUNCTIONS_H
#define IMU_HANDLER_FUNCTIONS_H

int FileExists();
void DriverSignalHandler(int signum);
void TimerSignalHandler(int signum);
void UpdateCurrent();
void SetUpTimers();
#endif  // IMU_HANDLER_FUNCTIONS_H