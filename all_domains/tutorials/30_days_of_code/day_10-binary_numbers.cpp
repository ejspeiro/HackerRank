#include <cmath>

#include <iostream>

#include <vector>

int main () {

  int nn{};
  int rr{};
  std::vector<int> vv;

  std::cin >> nn;

  // Obtain binary representation of a number and store it safely in a vector.
  // O(log(nn)).
  while (nn != 0) {
    rr = nn%2;
    vv.insert(vv.begin(), rr);
    nn /= 2;
  }

  // Search longest length of occurrences of 1.
  // O(log(nn)*log(nn)).
  int longest_length{}; // Assume there is no longest length.
  for (int ii = 0; ii < vv.size(); ++ii) {
    int current_guess{};
    int ee{vv[ii]};
    while (ee == 1) {
      current_guess++;
      ii++;
      ee = vv[ii];
    }
    if (current_guess > longest_length) {
      longest_length = current_guess;
    }
  }
  std::cout << longest_length << std::endl;
}
