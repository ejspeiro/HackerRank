#include <iostream>

int main () {

  std::cout << 5 << std::endl;

  // YES.
  std::cout << 4 << ' ' << 3 << std::endl;
  std::cout << -1 << ' ' << -2 << ' ' << 4 << ' ' << 2 << std::endl;

  // NO.
  std::cout << 5 << ' ' << 2 << std::endl;
  std::cout << 0 << ' ' << -1 << ' ' << 2 << ' ' << 1 << ' ' << 3 << std::endl;

  // YES.
  std::cout << 6 << ' ' << 4 << std::endl;
  std::cout << 1 << ' ' << -2 << ' ' << 0 << ' ' << 2 << ' ' << 5 << ' ' << 6 << std::endl;

  // NO.
  std::cout << 7 << ' ' << 3 << std::endl;
  std::cout << 0 << ' ' << -1 << ' ' << -2 << ' ' << -1 << ' ' << 5 << ' ' << 6 << ' ' << 0 << std::endl;

  // YES.
  std::cout << 8 << ' ' << 3 << std::endl;
  std::cout << -1 << ' ' << -2 << ' ' << 4 << ' ' << 2 << ' ' << 5 << ' ' << -6 << ' ' << -7 << ' ' << -8 << std::endl;
}
