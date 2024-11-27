#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define PAGE_SIZE 4096

int main()
{
  FILE *file = fopen("./lorem_ipsum.txt", "r+");
  // int fd = open("./crawls.txt", O_RDWR, 0600);

  int count = 0;

  char ch = fgetc(file);

  while (ch != EOF)
  {
    if (ch >= 'A' && ch < 'Z' && (count % 2 == 0))
    {
      fseek(file, -1, SEEK_CUR); // move pointer one index back
      fputc(toupper(ch), file);
      fseek(file, 0, SEEK_CUR); // move pointer one index fowards
    }
    count++;
    ch = fgetc(file);
  }

  fclose(file);
  return 0;
}
