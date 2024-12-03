#include <stdio.h>

int main() {
  FILE *in = fopen("input.txt", "r");
  if (in == NULL) {
    perror("Couldn't open file");
    return 1;
  }

  int left, right, c, sum = 0, n = 0;
  while ((c = fgetc(in)) != EOF) {
    if (c == 'm') {
      if (fscanf(in, "ul(%d,%d)", &left, &right) == 2) {
        printf("%d, %d\n", left, right);
        sum += left * right;
        n++;
      }
    }
  }

  printf("\n------- %d, %d --------\n", sum, n);

  fclose(in);
  return 0;
}
