#include <iostream>

int Factorial(int nn) {

  if (nn == 1) {
    return 1;
  } else {
    return nn*Factorial(nn - 1);
  }
}

int main () {

  int nn{};

  std::cin >> nn;
  std::cout << Factorial(nn) << std::cout;
}
