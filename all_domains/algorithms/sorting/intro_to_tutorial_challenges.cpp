#include <iostream>

#include <vector>

#include <iterator>

#include <algorithm>

int main () {

  int nn{}; // Size of the array.
  int vv{}; // Value to be searched.

  std::cin >> vv;
  std::cin >> nn;

  std::vector<int> the_array(nn);   // The array.

  for (int ii = 0; ii < nn; ++ii) {
    std::cin >> the_array[ii];
  }

  std::sort(the_array.begin(), the_array.end());

  auto pos = std::lower_bound(the_array.begin(), the_array.end(), vv);

  std::cout << std::distance(the_array.begin(), pos) << std::endl;
}
