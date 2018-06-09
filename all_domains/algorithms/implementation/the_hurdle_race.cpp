// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  size_t nn{};  // Total amount of hurdle heights.
  size_t kk{};  // Maximum height Tom can jump.

  std::cin >> nn >> kk;
  std::vector<int> heights(nn);

  for (int &height : heights) {
    std::cin >> height;
  }
  int max_height = *std::max_element(heights.cbegin(), heights.cend());
  if (kk >= max_height) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << max_height - kk << std::endl;
  }
}
