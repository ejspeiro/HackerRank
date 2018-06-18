// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

bool CanDecompose(const std::vector<int> &the_array) {
  int total_sum{std::accumulate(the_array.begin(), the_array.end(), 0)};

  if (total_sum%2 != 0) {
    return false;
  }
  return true;
}

int MaxScore(const std::vector<int> &the_array) {
  if (CanDecompose(the_array)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  std::vector<int> the_array;  // Array of elements.
  int num_test_cases{};  // Number of test cases.
  int array_size{};  // Size of the array to read.

  std::cin >> num_test_cases;
  for (int tt = 1; tt <= num_test_cases; ++tt) {
    std::cin >> array_size;
    the_array.resize(array_size);
    for (int ii = 0; ii < array_size; ++ii) {
      try {
        std::cin >> the_array.at(ii);
      } catch (const std::out_of_range &oor) {
        std::cerr << "Out of range error: " << oor.what() << std::endl;
      }
    }
    std::cout << MaxScore(the_array) << std::endl;
  }
}
