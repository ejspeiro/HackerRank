#include <iostream>
#include <string>

int main() {

  std::string inputString{};

  getline(std::cin, inputString);
  std::cout << "Hello, World." << std::endl;
  std::cout << inputString << std::endl;
}
