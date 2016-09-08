#include <iostream>

#include <tuple>

int main () {

  int aa{}; // First component of tuples.
  int bb{}; // Second component of tuples.
  int cc{}; // Third component of tuples.

  std::cin >> aa >> bb >> cc;

  std::tuple<int, int, int> ta{aa, bb, cc};

  std::cin >> aa >> bb >> cc;

  std::tuple<int, int, int> tb{aa, bb, cc};

  int sum_ta{}; // Sum of scores from whoever owns tuple a.
  int sum_tb{}; // Sum of scores from whoever owns tuple b.

  if (std::get<0>(ta) < std::get<0>(tb)) {
    sum_tb++;
  } else if (std::get<0>(ta) > std::get<0>(tb)) {
    sum_ta++;
  }

  if (std::get<1>(ta) < std::get<1>(tb)) {
    sum_tb++;
  } else if (std::get<1>(ta) > std::get<1>(tb)) {
    sum_ta++;
  }

  if (std::get<2>(ta) < std::get<2>(tb)) {
    sum_tb++;
  } else if (std::get<2>(ta) > std::get<2>(tb)) {
    sum_ta++;
  }

  std::cout << sum_ta << ' ' << sum_tb << std::endl;
}
