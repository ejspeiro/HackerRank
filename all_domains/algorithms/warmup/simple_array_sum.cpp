#include <iostream>

#include <vector>

#include <numeric>

int main () {

  int nn{}; // Size of the array.

  std::cin >> nn;

  std::vector<int> the_array(nn);   // The array.

  for (int &ee: the_array) {
    std::cin >> ee;
  }
  std::cout << std::accumulate(the_array.cbegin(), the_array.cend(), 0) <<
    std::endl;
}
