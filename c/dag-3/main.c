#include <stdio.h>
int main() {
  FILE *in = fopen("input.txt", "r");

  int left, right, sum = 0;
  while (fscanf(in, "mul(%d, %d)", &left, &right) == 2) {
    printf("%d, %d\n", left, right);
    sum += left * right;
  }

  printf("\n------- %d --------\n", sum);

  fclose(in);
  return 0;
}
