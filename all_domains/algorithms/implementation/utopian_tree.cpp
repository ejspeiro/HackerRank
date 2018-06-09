// Copyright 2018 Eduardo Sanchez
#include <iostream>

int FinalHeight(int num_cycles) {
  constexpr int kStartingHeight_m{1};  // Starting height of the tree [m].
  int final_height{kStartingHeight_m};  // Final height.

  for (int ii = 1; ii <= num_cycles; ++ii) {
    if (ii%2 != 0) {
      final_height *= 2;
    } else {
      final_height++;
    }
  }
  return final_height;
}

int main() {
  int tt{};  // Number of test cases.

  std::cin >> tt;
  for (auto ii = 0; ii < tt; ++ii) {
    int num_cycles{};  // Number of cycles.

    std::cin >> num_cycles;
    std::cout << FinalHeight(num_cycles) << std::endl;
  }
}
