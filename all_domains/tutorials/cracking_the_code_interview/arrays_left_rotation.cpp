#include <iostream>

#include <vector>

int main () {

  int nn{}; // Number of integers.
  int dd{}; // Number of rotations to perform.

  std::cin >> nn >> dd;

  std::vector<int> vv(nn);  // Vector (array) to contain input.

  for (int ii = 0; ii < nn; ++ii) {
    std::cin >> vv.at(ii);
  }

  // What is the index of vv[0] after dd rotations?
  int new_idx = nn - (dd%nn);

  std::vector<int> ww(nn);    // Contains the result of dd rotations, dd > 0.

  // Copy upper half of the vv array into the ww array.
  for (int ii = 0; ii < (nn - new_idx); ++ii) {
    ww.at(new_idx + ii) = vv.at(ii);
  }
  // Copy lower half of the vv array into the ww array.
  for (int ii = 0; ii < new_idx; ++ii) {
    ww.at(ii) = vv.at(dd + ii);
  }
  for (const int &elem: ww) {
    std::cout << elem << ' ';
  }
}
