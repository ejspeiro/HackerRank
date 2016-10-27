#include <iostream>

#include <string>

#include <algorithm>

int main () {

  std::string line{};   // Line to process.

  getline(std::cin, line);

  // Remove all spaces.
  auto pos = std::remove(line.begin(), line.end(), ' ');

  // Erase the "removed" elements is the container.
  line.erase(pos, line.end());

  // Make all lowercase letters.
  for (char &cc: line) {
    cc = std::tolower(cc);
  }

  // Sort the line.
  std::sort(line.begin(), line.end());

  // Remove duplicate letter.
  pos = std::unique(line.begin(), line.end());

  // Erase the "removed" elements is the container.
  line.erase(pos, line.end());

  if (line.size() == 26) {
    std::cout << "pangram" << std::endl;
  } else {
    std::cout << "not pangram" << std::endl;
  }
}
