#include <iostream>

bool IsPrime (int xx) {

  if (xx <= 1) {
    return false;
  } else if (xx == 2) {
    return true;
  } else if ((xx%2) == 0) {
    return false;
  } else {

    double xx_d{static_cast<double>(xx)};
    int upper_limit{static_cast<int>(sqrt(xx_d) + 1)};

    int ii{3};
    while (ii <= upper_limit) {
      if ((ii%xx) == 0) {
        return false;
      } else {
        ii += 2;
      }
    }
    return true;
  }
}

int MaxFactor(int nn) {


}

int ComputeMinNumMoves(int nn) {

  int cc{};
  while (nn >= 0) {
    if (IsPrime(nn)) {
      nn--;
    } else {
      // N is not prime.
      // N = a x b.
      nn = MaxFactor(nn);
    }
    cc++;
  }
  return cc;
}

int main() {

  int qq{};

  std::cin >> qq;

  for (int ii = 1; ii <= qq; ++ii) {
    int nn{};
    std::cin >> nn;
    std::cout << ComputeMinNumMoves(nn) << std::endl;
  }
}
