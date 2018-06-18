// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> healt_pts{};  // Array of health points.
  int num_test_cases{};  // Number of test cases.
  int num_healt_pts{};  // curr_strengthize of the array to read.

  std::cin >> num_test_cases;
  for (int tt = 1; tt <= num_test_cases; ++tt) {
    std::cin >> num_healt_pts;
    healt_pts.resize(num_healt_pts);
    int32_t sum_healt_pts{};

    for (int ii = 0; ii < num_healt_pts; ++ii) {
      try {
        std::cin >> healt_pts.at(ii);
        sum_healt_pts += static_cast<int32_t>(healt_pts.at(ii));
      } catch (const std::out_of_range &oor) {
        std::cerr << "Out of range error: " << oor.what() << std::endl;
      }
    }
    std::sort(healt_pts.begin(), healt_pts.end());

    int32_t curr_strength{1l};
    int32_t max_sum_health_pts = sum_healt_pts;
    int32_t curr_exp{};

    for (int ii = 0l; ii < num_healt_pts; ii++) {
      curr_strength++;
      sum_healt_pts -= healt_pts[ii];
      curr_exp = sum_healt_pts*curr_strength;
      // Save the biggest solution.
      if (curr_exp > max_sum_health_pts) {
        max_sum_health_pts = curr_exp;
      }
    }
    std::cout << max_sum_health_pts << std::endl;
  }
}
