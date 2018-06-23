// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <vector>

int64_t constexpr nn = 70;

std::vector<int64_t> buffer(nn + 1);

int64_t FF(int64_t nn) {
  if (nn < 3ll) {
    return 7ll;
  } else {
    if (buffer[nn] != -1) {
      return buffer[nn];
    } else {
      buffer[nn - 1ll] = FF(nn - 1ll);
      buffer[nn - 3ll] = FF(nn - 3ll);
      return buffer[nn - 1ll] + buffer[nn - 3ll];
    }
  }
}

int main() {
  int64_t nn{};

  std::cin >> nn;
  for (int64_t &ee : buffer) {
    ee = -1;
  }
  std::cout << FF(nn) << std::endl;
}
