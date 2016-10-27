#include <iostream>

#include <vector>

#include <utility>

int main () {

  int nn = int();   // Size of the array.

  std::cin >> nn;

  std::vector<int> the_array(nn);

  for (int ii = 0; ii < nn; ++ii) {
    std::cin >> the_array.at(ii);
  }

  int cc = nn - 2;

  int ee = the_array.at(nn - 1);

  while (the_array[cc] > ee && cc >= 0) {
    the_array[cc + 1] = the_array[cc];

    for (int ii = 0; ii < nn; ++ii) {
      std::cout << the_array.at(ii) << ' ';
    }
    std::cout << std::endl;

    cc--;
  }

  the_array.at(cc + 1) = ee;

  for (int ii = 0; ii < nn; ++ii) {
    std::cout << the_array.at(ii) << ' ';
  }
  std::cout << std::endl;
}
