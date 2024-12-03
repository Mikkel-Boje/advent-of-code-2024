#include <stdio.h>

int main() {
  FILE *in = fopen("input.txt", "r");
  if (in == NULL) {
    perror("Couldn't open file");
    return 1;
  }

  char in_levels[64] = {0};

  int levels[16] = {0};
  char num[8] = "";
  int digit = 0;

  int counter = 0;
  while (fgets(in_levels, sizeof(levels), in)) {
    for (int i = 0; i < sizeof(in_levels) / sizeof(in_levels[0]); i++) {
      if (in_levels[i] == ' ') {
        num[digit] = '\0';
        digit = 0;
        if (sscanf(num, "%d", &levels[counter]) != 1) {
          perror("Failed conversion on sscanf");
          goto close;
        }
        num[0] = '\0';
        continue;
      }
      if (!digit) {
        printf("Adding {%d}\n", in_levels[i] - '0');
        num[digit] = in_levels[i] - '0';
        digit++;
      }
    }
  }

  for (int i = 0; i < sizeof(levels) / sizeof(levels[0]); i++) {
    printf("{%d}", levels[i]);
  }
  printf("\n");

close:
  fclose(in);
  return 0;
}
