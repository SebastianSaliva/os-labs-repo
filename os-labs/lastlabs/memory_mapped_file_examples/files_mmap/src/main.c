#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define PAGE_SIZE 4096

// this code is used to r/w a file at any given index using a memory block

int main()
{
  int fd = open("./crawls.txt", O_RDWR, S_IRUSR | S_IWUSR);
  // int fd = open("./crawls.txt", O_RDWR, 0600);
  printf("%x\n", S_IRUSR | S_IWUSR);

  printf("%x\n", 0600);

  printf("file descriptor: %d\n", fd);

  struct stat sb;

  fstat(fd, &sb);

  printf("file has %ld blocks because its size is: %ld \n", sb.st_blocks,
         sb.st_size);

  char *file_block =
      mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  printf("the third letter of the file is: %c \n", file_block[2]);

  file_block[4] = toupper(file_block[4]);

  return 0;
}
