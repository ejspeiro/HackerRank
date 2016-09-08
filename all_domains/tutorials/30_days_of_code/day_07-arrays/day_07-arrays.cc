#include <iostream>

#include <vector>

int main() {

  int nn;

  std::cin >> nn;

  std::vector<int> the_array(nn);

  for(int ii = 0; ii < nn; ++ii) {
    std::cin >> the_array[ii];
  }

  for(int ii = nn - 1; ii >= 0; --ii) {
    std::cout << the_array[ii] << ' ';
  }
  std::cout << std::endl;
}
