#include <stdio.h>

int main() {
  int a;
  int b;
  scanf("%d\n%d", &a, &b);
  for (size_t ii = a; ii <= b; ++ii ) {
    switch (ii) {
      case 1: {
        fprintf(stdout, "one\n");
        break;
      }
      case 2: {
        fprintf(stdout, "two\n");
        break;
      }
      case 3: {
        fprintf(stdout, "three\n");
        break;
      }
      case 4: {
        fprintf(stdout, "four\n");
        break;
      }
      case 5: {
        fprintf(stdout, "five\n");
        break;
      }
      case 6: {
        fprintf(stdout, "six\n");
        break;
      }
      case 7: {
        fprintf(stdout, "seven\n");
        break;
      }
      case 8: {
        fprintf(stdout, "eight\n");
        break;
      }
      case 9: {
        fprintf(stdout, "nine\n");
        break;
      }
      default: {
        if (ii%2 == 0) {
          fprintf(stdout, "even\n");
        } else {
          fprintf(stdout, "odd\n");
        }
        break;
      }
    }
  }
  return 0;
}
