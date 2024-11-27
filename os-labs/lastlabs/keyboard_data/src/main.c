#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <unistd.h>

void quit(void) { exit(0); }

int main() {
  // Replace with your keyboard's device file
  const char *device = "/dev/input/event2";
  int fd = open(device, O_RDONLY);
  if (fd == -1) {
    perror("Error opening device");
    return 1;
  }

  struct input_event ev;

  int current_key = 0;
  int previous_key = 0;

  printf("Listening for keyboard events. Press Ctrl+C to quit.\n");
  while (1) {
    // Read an event
    if (read(fd, &ev, sizeof(struct input_event)) ==
        sizeof(struct input_event)) {
      if (ev.type == EV_KEY && ev.value == 1) {  // Key press event
        printf("Key %d pressed.\n", ev.code);
        previous_key = current_key;
        current_key = ev.code;
      }
      if (ev.type == EV_KEY && ev.value == 0) {  // Key release event
        printf("Key %d released.\n", ev.code);
        previous_key = -1;
        current_key = -1;
      }

      /// evalua la combinacion ctrl+k
      if (previous_key == 29 && current_key == 37) {
        quit();
      }
    }
  }

  close(fd);
  return 0;
}
