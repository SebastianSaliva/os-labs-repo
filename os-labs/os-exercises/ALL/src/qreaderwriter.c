// queue
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// msg struct to be sent
struct mesg_buffer {
  long mesg_type;
  int mesg_text;
};

void reading_from_queue() {
  key_t key = ftok("/tmp", 65);  // create message queue key
  if (key == -1) printf("errorftok");

  int msgid = msgget(key, 0666 | IPC_CREAT);  // create a message queue

  struct mesg_buffer message;

  // msgrcv to receive message
  msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0);

  // to destroy the message queue
  msgctl(msgid, IPC_RMID, NULL);
}

void writing_to_queue() {
  key_t key = ftok("/tmp", 65);  // create message queue key
  if (key == -1) printf("errorftok");

  int msgid = msgget(key, 0666 | IPC_CREAT);  // create a message queue

  struct mesg_buffer message;
  message.mesg_type = 1;  // idk what this is, you can set it only once if not
                          // changing type i think

  // msgsnd to send message
  message.mesg_text = 12345678;  // using int cuz its def in mesg_buffer
  msgsnd(msgid, &message, sizeof(message.mesg_text), 0);

  // msgctl(msgid, IPC_RMID, NULL); // to detroy queue
}

int main() {
  // queues

  return 0;
}