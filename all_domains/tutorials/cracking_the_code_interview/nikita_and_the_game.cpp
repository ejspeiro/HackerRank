#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> discovered_first_half;
std::vector<bool> discovered_second_half;

bool CanDecompose(const std::vector<int> &aa) {

  if (aa.size() == 1) {
    return false;
  }

  int sum = accumulate(aa.begin(), aa.end(), 0);

  if (sum%2 != 0) {
    return false;
  }

  int nn{static_cast<int>(aa.size())};
  int past{};
  int total_cost{};
  for (int ii = 1; ii <= nn/2; ++ii) {
    int present{};
    int curr_max{};
    for (int jj = 1; jj <= nn; ++jj) {
      if (!discovered_first_half[jj] && past + aa[jj] > curr_max && past + aa[jj] <= sum/2) {
        present = past + aa[jj];
        curr_max = present;
        total_cost += present;
        discovered_first_half[jj] = true;
      }
    }
    if (total_cost == sum/2) {
      break;
    } else {
      past = present;
    }
    curr_max = 0;
  }
  if (total_cost != sum/2) {
    return false;
  }
  past = 0;
  for (int ii = 1; ii <= nn/2; ++ii) {
    int curr_max{};
    int present{};
    for (int jj = 1; jj <= nn; ++jj) {
      if (!discovered_second_half[jj] && past + aa[jj] > curr_max && past + aa[jj] <= sum/2) {
        present = past + aa[jj];
        curr_max = present;
        total_cost += present;
        discovered_second_half[jj] = true;
      }
    if (total_cost == sum/2) {
      break;
    } else {
      past = present;
    }
      curr_max = 0;
    }
  }
  if (total_cost != sum) {
    return false;
  }

  return true;
}

std::vector<int> ComputeRightHalfOf(const std::vector<int> &aa) {

  std::vector<int> half;

  for (size_t ii = 1; ii <= discovered_second_half.size(); ++ii) {
    if (discovered_second_half[ii]) {
      half.push_back(aa[ii]);
    }
  }
  return half;
}

int MaxScore(const std::vector<int> &aa) {

  bool decomp = CanDecompose(aa);

  if (decomp) {
    return 1 + MaxScore(ComputeRightHalfOf(aa));
  } else {
    return 0;
  }
}

int main() {

  int tt{}; // Number of test cases.

  std::cin >> tt;

  for (int ii = 1; ii <= tt; ++ii) {
    int nn{}; // Number of integers.
    std::cin >> nn;
    std::vector<int> aa(nn + 1);  // The array.
    for (int ee = 1; ee <= nn; ++ee) {
      std::cin >> aa[ee];
    }

    for (int ii = 0; ii <= (nn + 1)/2; ii++) {
      discovered_first_half.push_back(false);
      discovered_second_half.push_back(false);
    }

    std::cout << MaxScore(aa) << std::endl;
  }
}
