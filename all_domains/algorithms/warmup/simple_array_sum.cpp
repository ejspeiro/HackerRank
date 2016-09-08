#include <iostream>

#include <vector>

#include <algorithm>

int main () {

  int nn{}; // Size of the array.

  std::cin >> nn;

  std::vector<int> the_array(nn);

  for (int ii = 0; ii < nn; ++ii) {
    std::cin >> the_array[ii];
  }
  
}