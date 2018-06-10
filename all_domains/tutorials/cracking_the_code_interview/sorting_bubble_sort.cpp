// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <memory>

int BubbleSortCountSwaps(const std::unique_ptr<int[]> &a, int n) {
  int num_swaps{};  // Number of swaps.

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
          // Swap adjacent elements if they are in decreasing order
          if (a[j] > a[j + 1]) {
              std::swap(a[j], a[j + 1]);
              num_swaps++;
          }
      }
  }
  return num_swaps;
}

int main() {
  int nn{};  // Number of elements in the array.

  std::cin >> nn;

  std::unique_ptr<int[]> the_array(new int[nn]);

  for (int ii = 0; ii < nn; ++ii) {
    int element{};  // Element to be read.
    std::cin >> element;
    the_array[ii] = element;
  }

  int count = BubbleSortCountSwaps(the_array, nn);

  std::cout << "Array is sorted in " << count << " swaps." << std::endl;
  std::cout << "First Element: " << the_array[0] << std::endl;
  std::cout << "Last Element: " << the_array[nn - 1] << std::endl;
}
