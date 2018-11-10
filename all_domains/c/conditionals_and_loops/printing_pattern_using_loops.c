#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    // First half of the matrix.
    for (int rr = 0; rr < n; ++rr) {
      // 7 6 5 4 3 3 3 3 3 4 5 6 7
      // 7 6 5 4 - - - - - - - - -
      for (int aa = 0; aa < rr; ++aa) {
        printf("%d ", n - aa);
      }
      // - - - - 3 3 3 - - - - - -
      for (int bb = 1; bb < n - rr; ++bb) {
        printf("%d ", n - rr);
      }
      // The previous loop prints the center before getting to this point.
      //               3 3 - - - -
      for (int bb = 1; bb <= n - rr; ++bb) {
        printf("%d ", n - rr);
      }
      //                   4 5 6 7
      for (int aa = n - rr; aa < n; ++aa) {
        printf("%d ", aa + 1);
      }
      printf("\n");
    }
    for (int rr = n - 2; rr >= 0; --rr) {
      for (int aa = 0; aa < rr; ++aa) {
        printf("%d ", n - aa);
      }
      for (int bb = 1; bb < n - rr; ++bb) {
        printf("%d ", n - rr);
      }
      for (int bb = 1; bb <= n - rr; ++bb) {
        printf("%d ", n - rr);
      }
      for (int aa = n - rr; aa < n; ++aa) {
        printf("%d ", aa + 1);
      }
      printf("\n");
    }
    return 0;
}
