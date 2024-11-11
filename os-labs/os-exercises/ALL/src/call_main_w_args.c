
#define N 5
#define N_OF_EXPECTED_ARGS N

int main(int argc, char* argv[]) {
  /* name is always passed as argv[0] */

  if (argc == 1)
    printf("No arguments provided.");
  else {
    for (int i = 1; i < argc; i++)
      printf("if ints are passed use this %d", atoi(argv[i + 1]));
  }
}