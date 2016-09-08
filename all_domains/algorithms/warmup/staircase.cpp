#include <iostream>

int main () {

  int nn{}; // Height and width of the staircase.

  std::cin >> nn;

  // Per each level of the staircase.
  for (int ii = 1; ii <= nn; ++ii) {
    // Paint spaces first.
    for (int jj = 1; jj <= nn - ii; ++jj) {
      std::cout << ' ';
    }
    // Paint signs now.
    for (int jj = 1; jj <= ii; ++jj) {
      std::cout << '#';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

