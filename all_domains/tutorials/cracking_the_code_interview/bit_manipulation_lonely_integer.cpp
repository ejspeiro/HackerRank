// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <vector>

int main() {
  size_t nn{};  // Number of integers.

  std::cin >> nn;

  constexpr uint16_t k101{101};  // 100 as a constant.
  std::vector<int> fo(k101);  // First occurrence.

  for (size_t ii = 1; ii <= nn; ++ii) {
    size_t idx{};  // Read integer/vector index.

    // A = [1]
    std::cin >> idx;
    fo.at(idx)++;
  }

  // Find non-repeated element.
  constexpr uint16_t kTwo{2};  // 2 as a constant.
  for (size_t ii = 0; ii < fo.size(); ++ii) {
    if (fo.at(ii) > 0 && fo.at(ii) != kTwo) {
      std::cout << ii << std::endl;
      break;
    }
  }
}
