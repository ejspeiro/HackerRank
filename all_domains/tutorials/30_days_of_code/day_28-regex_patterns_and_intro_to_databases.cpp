#include <iostream>

#include <string>
#include <regex>

#include <set>

int main() {

  int nn{};   // Number of test cases.
  std::cin >> nn;
  std::regex pattern(".+@gmail\\.com$");    // Reg. exp. for a gmail email.
  std::multiset<std::string> data_base;

  for (int a0 = 0; a0 < nn; a0++) {
    std::string name;
    std::string mail;
    std::cin >> name >> mail;
    if (std::regex_match(mail,pattern)) {
      data_base.insert(name);
    }
  }
  for(auto &ee: data_base) {
    std::cout << ee << std::endl;
  }
}
