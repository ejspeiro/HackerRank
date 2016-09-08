#include <iostream>

int main() {

  int nn;

  std::cin >> nn;

  if (nn%2 != 0) {
    // nn is odd.
    std::cout << "Weird" << std::endl;
  } else if (2 <= nn && nn <= 5) {
    // nn is even.
    std::cout << "Not Weird" << std::endl;
  } else if (6 <= nn && nn <= 20) {
    // nn is even.
    std::cout << "Weird" << std::endl;
  } else {
    // nn is even.
    std::cout << "Not Weird" << std::endl;
  }
}
