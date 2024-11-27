#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// this just copies a file to another char by char with open

int main()
{
  int source, dest;
  char ch;

  // Open the source file in read-only mode
  source = open(
      "/home/juan/Documents/OS/class_examples/complete_examples/"
      "files_copy_fopen/build/crawls.txt",
      O_RDONLY);
  if (source == -1)
  {
    perror("Error opening source file");
    return 1;
  }

  // Open the destination file in write-only mode, create if it doesn't exist
  // O_APPEND would append to the file, O_TRUNC would truncate (replace) it
  dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (dest == -1)
  {
    perror("Error opening destination file");
    close(source);
    return 1;
  }

  // Copy each character from source to destination
  while (read(source, &ch, 1) == 1)
  {
    if (write(dest, &ch, 1) != 1)
    {
      perror("Error writing to destination file");
      close(source);
      close(dest);
      return 1;
    }
  }

  // Close both files
  close(source);
  close(dest);

  printf("File copied successfully.\n");
  return 0;
}