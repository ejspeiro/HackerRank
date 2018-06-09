// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <vector>

bool OkToAdd(int element, const std::vector<int> &buffer) {
  bool ok_to_add{true};  // Can I add the element in the buffer?

  size_t ii{};  // Index.

  while (ok_to_add && ii < buffer.size()) {
    ok_to_add = abs(element - buffer.at(ii)) <= 1? true: false;
    ++ii;
  }
  return ok_to_add;
}

int CountUnitDiffSubArrays(const std::vector<int> &the_array) {
  size_t greatest_length{};  // Greatest length so far.

  for (size_t ii = 0; ii < the_array.size(); ++ii) {
    for (size_t jj = ii + 1; jj < the_array.size(); ++jj) {
      std::vector<int> buffer{};  // Temporary buffer to explore.

      buffer.push_back(the_array.at(ii));
      for (size_t kk = jj; kk < the_array.size(); ++kk) {
        int candidate{the_array[kk]};  // Candidate to be added to solution.
        if (OkToAdd(candidate, buffer)) {
          buffer.push_back(candidate);
        }
      }
      if (buffer.size() > greatest_length) {
        greatest_length = buffer.size();
      }
    }
  }
  return static_cast<int>(greatest_length);
}

int main() {
  size_t nn{};  // Number of elements in the array.

  std::cin >> nn;

  std::vector<int>  the_array{};  // Array of numbers.

  for (size_t ii = 0; ii < nn; ++ii) {
    int element{};  // Element in the array.

    std::cin >> element;

    the_array.push_back(element);
  }

  std::cout << CountUnitDiffSubArrays(the_array) << std::endl;
}
