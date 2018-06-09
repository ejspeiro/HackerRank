// Copyright 2018 Eduardo Sanchez
#include <iostream>

int main() {
  int numTestCases{};
  int nn{};
  int kk{};

  std::cin >> numTestCases;

  for (int ii = 0; ii < numTestCases; ++ii) {
    int aa{};
    int numPresent{};

    std::cin >> nn >> kk;
    for (int jj = 0; jj < nn; ++jj) {
      std::cin >> aa;
      numPresent += (aa <= 0)? 1: 0;
    }
    if (numPresent < kk) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}
