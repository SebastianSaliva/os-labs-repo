#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define PAGE_SIZE 4096

int main() {
  int fd = open("./lorem_ipsum.txt", O_RDWR, S_IRUSR | S_IWUSR);

  struct stat sb;

  fstat(fd, &sb);

  char* file_block =
      mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  if (file_block == -1) {
    perror("error in mmap");
    exit(0);
  }

  for (int i = 1; i < sb.st_size; i = i + 2) {
    if (file_block[i] >= 'A' && file_block[i] <= 'Z') {
      file_block[i] = tolower(file_block[i]);
    } else {
      file_block[i] = toupper(file_block[i]);
    }
  }

  return 0;
}
