#include <iostream>

#include <vector>

#include <numeric>

int main () {

  unsigned short int nn{};  // Number of long long integers to read.

  std::cin >> nn;

  std::vector<unsigned long long int> aa(nn);

  for (unsigned long long int &ee: aa) {
    std::cin >> ee;
  }
  std::cout << std::accumulate(aa.cbegin(), aa.cend(), 0ull) << std::endl;
}
