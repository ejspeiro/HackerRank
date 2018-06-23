// Copyright 2018 Eduardo Sanchez
#include <cmath>

#include <iostream>
#include <iomanip>
#include <vector>

int main() {
  uint32_t nn{};
  uint32_t count{};

  std::cin >> nn;

  uint32_t count = 0ul;

  while (nn) {
    count += nn%2ul? 0ul: 1ul;
    nn/=2ul;
  }
  count = pow(2ul, count);
  std::cout << count << std::endl;
}
