#include <cmath>

#include <iostream>

#include <vector>

int main () {

  int nn{}; // Rank of the matrix. ***

  std::cin >> nn;

  std::vector<int> mm(nn*nn);   // The matrix.

  // Read matrix in.
  for (int ii = 0; ii < nn; ++ii) {
    for (int jj = 0; jj < nn; ++jj) {
      std::cin >> mm.at(ii*nn + jj);
    }
  }

  // Compute the sum of the primary diagonal.
  int prim_sum{};
  for (int ii = 0; ii < nn; ++ii) {
    prim_sum += mm.at(ii*nn + ii);
  }

  // Compute the sum of the secondary diagonal.
  int seco_sum{};
  for (int ii = 0; ii < nn; ++ii) {
    seco_sum += mm.at(ii*nn + ((nn - 1) - ii));
  }

  std::cout << abs(prim_sum - seco_sum) << std::endl;
}
