#include "functions.h"
int main() {
  int lenH = 4;
  int lenW = 20;

  char **text;
  text = malloc(lenH * sizeof(char *));
  for (int i = 0; i < lenH; i++) {
    text[i] = malloc(lenW * sizeof(char));
  }

  gets(text[0]);
}
void getText(char **txt) { gets(txt[0]); }