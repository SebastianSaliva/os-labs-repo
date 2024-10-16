#ifndef SUPERVISOR_FUNCTIONS_H
#define SUPERVISOR_FUNCTIONS_H

int GetPidByName(const char *process_name);
int LaunchNewImuHandler();
void SupervisorSignalHandler(int signum);
void SigchldHandler(int signum);
#endif  // SUPERVISOR_FUNCTIONS_H