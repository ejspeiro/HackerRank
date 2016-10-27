#include <iostream>

#include <string>

#include <stdexcept>

int main() {

  std::string ss;   // String to read.

  std::cin >> ss;

  try {
    int aux = std::stoi(ss);
    std::cout << aux << std::endl;
  } catch (const std::invalid_argument &ee) {
    std::cout << "Bad String" << std::endl;
  }
}
