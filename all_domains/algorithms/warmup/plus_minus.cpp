#include <iostream>

#include <vector>

int main () {

  int nn{}; // Amount of integers.

  std::cin >> nn;

  std::vector<int> vv(nn);

  for (int &ee: vv) {
    std::cin >> ee;
  }

  int pos{};
  int neg{};
  int zer{};
  for (const int &ee: vv) {
    if (ee > 0) {
      pos++;
    } else if (ee < 0) {
      neg++;
    } else {
      zer++;
    }
  }
  float float_size = static_cast<float>(vv.size());
  std::cout << static_cast<float>(pos)/float_size << std::endl;
  std::cout << static_cast<float>(neg)/float_size << std::endl;
  std::cout << static_cast<float>(zer)/float_size << std::endl;
}
