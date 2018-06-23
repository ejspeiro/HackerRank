// Copyright 2018 Eduardo Sanchez
#include <iostream>

int64_t Fibonacci(int nn, int t1, int t2) {
  if (nn <= 0) {
    return t1;
  } else if (nn == 1) {
    return t2;
  } else {
    return Fibonacci(nn - 2, t1, t2) +
      Fibonacci(nn - 1, t1, t2)*Fibonacci(nn - 1, t1, t2);
  }
}

int main() {
  int64_t t1;
  int64_t t2;
  int nn;

  std::cin >> t1;
  std::cin >> t2;
  std::cin >> nn;

  std::cout << Fibonacci(nn, t1, t2) << std::endl;
}
