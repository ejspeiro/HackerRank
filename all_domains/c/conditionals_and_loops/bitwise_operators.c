#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

void calculate_the_maximum(int n, int k) {
  int max_and = 0;
  int max_ior = 0;
  int max_xor = 0;
  for (size_t ii = 1; ii <= n; ++ii) {
    for (size_t jj = 1; jj <= n; ++jj) {
      if (ii != jj) {      
        int res_and = ii & jj;
        if (res_and < k && res_and > max_and) {
          max_and = res_and;
        }
        int res_ior = ii | jj;
        if (res_ior < k && res_ior > max_ior) {
          max_ior = res_ior;
        }
        int res_xor = ii ^ jj;
        if (res_xor < k && res_xor > max_xor) {
          max_xor = res_xor;
        }
      }
    }
  }
  printf("%d\n", max_and);
  printf("%d\n", max_ior);
  printf("%d\n", max_xor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
