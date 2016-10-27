#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
  
  int nn{}; // Size of the array.
  
  std::cin >> nn;
  
  std::vector<int> num_occurrences_of(101, 0); // The array.
  
  for (int ii = 0; ii < nn; ++ii) {
    int ee{}; // Current element.
    std::cin >> ee;
    num_occurrences_of[ee]++;
  }
  
  int n1{1};
  auto pos = std::find(num_occurrences_of.begin(), num_occurrences_of.end(), n1);
  
  std::cout << std::distance(num_occurrences_of.begin(), pos);
}
