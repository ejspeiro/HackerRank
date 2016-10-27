#include <iostream>

#include <string>
#include <regex>

bool RemovePair(std::string &ss) {

  bool found{};     // Have I found and removed something?
  std::smatch mm{}; // Details of the matches.
  try {
    std::regex pp("([a-z])\\1");  // Pattern to search for.
    found = std::regex_search(ss, mm, pp);
  } catch (const std::regex_error &ee) {
    std::cerr << "ERROR in regular expression: ";
    std::cerr << ee.what() << std::endl;
  }
  if (found) {
    ss.erase(mm.position(), 2);
  }
  return found;
}

int main () {

  std::string ss{}; // String to be used.

  getline(std::cin, ss);

  while (RemovePair(ss)) {}

  if (ss.empty()) {
    std::cout << "Empty String" << std::endl;
  } else {
    std::cout << ss << std::endl;
  }
}
