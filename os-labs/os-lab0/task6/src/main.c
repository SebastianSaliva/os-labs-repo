#include "functions.h"
int main() {
  int nf = 4;
  int nc = 20;

  char **text;
  text = malloc(nf * sizeof(char *));
  for (int i = 0; i < nf; i++) {
    text[i] = malloc(nc * sizeof(char));
  }

  gets(text[0]);
}
void getText(char **txt) { gets(txt[0]); }