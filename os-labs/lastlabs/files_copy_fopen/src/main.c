#include <stdio.h>

// this just copies a file to another char by char with fopen

int main()
{
  FILE *source, *dest;
  char ch;

  // Open the source file in read mode
  source = fopen("crawls.txt", "r");
  if (source == NULL)
  {
    perror("Error opening source file");
    return 1;
  }

  // Open the destination file in write mode
  dest = fopen("destination.txt", "w");
  if (dest == NULL)
  {
    perror("Error opening destination file");
    fclose(source);
    return 1;
  }

  // Copy each character from source to destination
  while ((ch = fgetc(source)) != EOF)
  {
    fputc(ch, dest);
  }

  // Close both files
  fclose(source);
  fclose(dest);

  printf("File copied successfully.\n");
  return 0;
}