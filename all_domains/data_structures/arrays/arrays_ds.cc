#include <iostream>

#include <vector>

int main () {

  int nn{}; // Number of integers.

  std::cin >> nn;

  std::vector<int> aa(nn);  // The array.

  for (int &ee: aa) {
    std::cin >> ee;
  }
  for (int ii = 0; ii < nn; ++ii) {
    std::cout << aa.back() << ' ';
    aa.pop_back();
  }
  std::cout << std::endl;
}
