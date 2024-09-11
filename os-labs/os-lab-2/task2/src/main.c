#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "functions.h"

#define MAXINLEN 100

int main() {
  while (1) {
    char **text = (char **)malloc(sizeof(char *));

    text[0] = (char *)malloc(MAXINLEN + 1 * sizeof(char));

    printf(">");
    fgets(text[0], MAXINLEN + 1, stdin);

    // removes unnecessary spaces, adds a ; at the end if it doesnt have one
    prep(text);

    int txtLen = strlen(text[0]);
    int i = 0;
    int ci = 0;

    char *currentCommand = (char *)malloc(txtLen * sizeof(char));

    char *txt = (char *)malloc(txtLen * sizeof(char));

    txt = text[0];

    for (i = 0; i < txtLen; i++) {
      if (txt[i] == ';') {
        if (currentCommand[ci - 1] == ' ') {
          ci--;
        }
        currentCommand[ci] = '\0';
        int words = 1;

        for (int n = 0; n < txtLen; n++)
          if (currentCommand[n] == ' ') words++;

        char **tokens = (char **)malloc(words * sizeof(char *));

        for (int j = 0; j < words; j++) {
          tokens[j] = (char *)malloc(strlen(currentCommand) * sizeof(char));
        }

        char *token = (char *)malloc(strlen(currentCommand) * sizeof(char));

        int tcount = 0;

        token = strtok(currentCommand, " ");

        while (token != NULL || tcount < words) {
          tokens[tcount] = token;
          tokens[tcount][strlen(token)] = '\0';  // Ensure null-termination
          tcount++;
          token = strtok(NULL, " ");
        }

        int pid = fork();

        if (!pid) {
          // in child process
          char *command = tokens[0];
          char *args[tcount + 1];
          int l = 0;
          for (l = 0; l < tcount; l++) {
            args[l] = tokens[l];
          }
          args[l] = NULL;

          execvp(command, args);
          perror("A command went wrong");
          exit(0);

        } else {
          // in parent process

          int *stat;
          waitpid(pid, stat, 0);
        }

        i++;
        ci = 0;
      } else {
        currentCommand[ci] = txt[i];
        ci++;
      }
    }
    free(text);
  }
  return 0;
}

void prep(char **text) {
  int i = 0;
  int prevwasspace = 0;

  char *out = (char *)malloc(strlen(text[0]) + 1 * sizeof(char));
  int offset = 0;
  while (isspace(text[0][i])) {
    i++;
    offset++;
  }

  while (text[0][i] != '\0') {
    if (!isspace(text[0][i])) {
      out[i - offset] = text[0][i];
      prevwasspace = 0;
    } else {
      if (prevwasspace) {
        offset++;
      } else {
        prevwasspace = 1;
        out[i - offset] = text[0][i];
      }
    }
    i++;
  }
  if (out[i - offset - 2] == ';') {
    out[i - offset - 1] = '\0';
  } else {
    out[i - offset - 1] = ';';
    out[i - offset] = '\0';
  }

  text[0] = out;
}