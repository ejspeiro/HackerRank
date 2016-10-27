#include <iostream>

#include <vector>

long long int constexpr nn = 70;

std::vector<long long int> buffer(nn + 1);

long long int FF(long long int nn) {

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

int main () {

  long long int nn{};

  std::cin >> nn;

  for (long long int &ee: buffer) {
    ee = -1;
  }

  std::cout << FF(nn) << std::endl;
}
