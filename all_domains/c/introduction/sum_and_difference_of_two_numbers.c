#include <stdio.h>

int main() {
  signed short int aa = 0;
  signed short int bb = 0;
  float            xx = 0.0f;
  float            yy = 0.0f;
  fscanf(stdin, "%d %d", &aa, &bb);
  fscanf(stdin, "%f %f", &xx, &yy);
  fprintf(stdout, "%d %d\n", aa + bb, aa - bb);
  fprintf(stdout, "%.1f %.1f\n", xx + yy, xx - yy);
  return 0;
}
