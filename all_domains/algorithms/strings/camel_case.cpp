#include <iostream>

#include <string>

#include <algorithm>

int main () {

  std::string line{};

  getline(std::cin, line);

  int count = std::count_if(line.begin(), line.end(), [] (const char &cc) {
    return std::isupper(cc);
  });

  std::cout << count + 1 << std::endl;
}
