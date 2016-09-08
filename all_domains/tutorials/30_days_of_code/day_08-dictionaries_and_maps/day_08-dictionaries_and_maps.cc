#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

int main() {

  int numTestCases = 0;

  std::map<std::string, std::string> phoneBook;

  cin >> numTestCases;

  for (int ii = 1; ii <= numTestCases; ++ii) {
    std::string name;
    std::string phone;
    cin >> name >> phone;
    phoneBook[name] = phone;
  }
  std::string query;
  while (cin >> query) {
    std::string result(phoneBook[query]);
    if (result == "") {
      std::cout << "Not found" << endl;
    } else {
      std::cout << query << '=' << result << std::endl;
    }
  }
}
