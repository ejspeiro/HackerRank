// Copyright 2018 Eduardo Sanchez
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

int main() {
  std::string hour{};  // Used hour.

  std::getline(std::cin, hour);

  std::istringstream inputString(hour.substr(0, 2));  // Input string.
  int hh{};  // Hour.

  inputString >> hh;
  if (hour.at(8) == 'A') {
    if (hh == 12) {
      std::cout << "00:" << hour.substr(3, hour.size() - 5) << std::endl;
    } else {
      std::cout << hour.substr(0, hour.size() - 2) << std::endl;
    }
  } else {
    if (hh == 12) {
      std::cout << "12:" << hour.substr(3, hour.size() - 5)
      << std::endl;
    } else {
      std::cout << hh + 12 << ':' << hour.substr(3, hour.size() - 5)
      << std::endl;
    }
  }
}
