#include <iostream>

#include <utility>

#include <vector>

int BubbleSort (std::vector<int> &a) {

  int n = a.size();
  int totalNumberOfSwaps = 0;

  for (int i = 0; i < n; i++) {
      // Track number of elements swapped during a single array traversal
      int numberOfSwaps = 0;

      for (int j = 0; j < n - 1; j++) {
          // Swap adjacent elements if they are in decreasing order
          if (a[j] > a[j + 1]) {
              std::swap(a[j], a[j + 1]);
              numberOfSwaps++;
          }
      }
      // If no elements were swapped during a traversal, array is sorted
      if (numberOfSwaps == 0) {
          break;
      }

      totalNumberOfSwaps += numberOfSwaps;
  }

  return totalNumberOfSwaps;
}

int main () {

  int nn{};

  std::cin >> nn;

  std::vector<int> aa(nn);

  for (int ii = 0; ii < nn; ii++) {
    std::cin >> aa.at(ii);
  }

  int nswaps = BubbleSort(aa);

  std::cout << "Array is sorted in " << nswaps << " swaps." << std::endl;
  std::cout << "First Element: " << aa.at(0) << std::endl;
  std::cout << "Last Element: " << aa.at(nn - 1) << std::endl;
}
