#include <iostream>

int solveMeFirst(int a, int b) {

  // Hint: Type return a+b; below
  return a + b;
}

int main() {

  int num1{};
  int num2{};
  int sum{};

  std::cin >> num1 >> num2;
  sum = solveMeFirst(num1, num2);
  std::cout << sum;
}
