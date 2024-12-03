#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define len 1000

int file_to_buffers(int *left, int *right);
int compare(const void *l, const void *r);

struct Counter {
  int num;
  int count;
};

int main() {
  int left[len] = {0};
  int right[len] = {0};
  if (file_to_buffers(left, right)) {
    return 1;
  }

  qsort(left, len, sizeof(left[0]), compare);
  qsort(right, len, sizeof(right[0]), compare);

  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += left[i] < right[i] ? right[i] - left[i] : left[i] - right[i];
  }

  printf("The total sum is: %d", sum);

  // Part 1: Done

  struct Counter counter[len] = {0};

  return 0;
}

int file_to_buffers(int *left, int *right) {
  FILE *in = fopen("input.txt", "r");
  if (in == NULL) {
    printf("Couldn't open input.txt");
    return 1;
  }

  int i = 0;
  while (fscanf(in, "%d %d", left + i, right + i) != EOF) {
    i++;
  }

  fclose(in);
  return 0;
}

int compare(const void *l, const void *r) { return (*(int *)l - *(int *)r); }
