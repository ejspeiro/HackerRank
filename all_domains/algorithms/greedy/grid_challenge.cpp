#include <iostream>

#include <algorithm>

#include <vector>

// YES
// NO

typedef std::vector<std::vector<char>> GridOfChar;

// Initially the CANDIDATE SET of chosen candidates is empty i.e., SOLUTION SET.
// At each step:
    // item will be added in a solution set by using SELECTION function.
    // IF the set would no longer be feasible (use FEASIBILITY FUNCTION)
        // reject items under consideration (and is never consider again).
    // ELSE IF set is still feasible THEN
        // add the current item.

bool CanWeRearrangeAsDesired(GridOfChar &gg) {

  bool ordered;

  // For each row...
  for (int rr = 0; rr < gg.size(); rr++) {
    // Execute gg.size() times the following action:
    for (int jj = 1; jj <= gg.size(); jj++) {
      //
      for (int ii = 0; ii < gg.size() - 1; ++ii) {
        if (gg[rr][ii] > gg[rr][ii + 1]) {
          std::swap(gg[rr][ii], gg[rr][ii + 1]);
        }
      }
      if (std::is_sorted(gg[rr].begin(), gg[rr].end())) {
        ordered = true;
        break;
      }
    }
    if (!ordered) {
      return false;
    }
  }

  // At this point, every row is lexicographically sorted. We must check if the
  // columns are.

  for (int cc = 0; cc < gg.size(); cc++) {
    std::vector<char> column;

    for (int rr = 0; rr < gg.size(); rr++) {
      column.push_back(gg[rr][cc]);
    }

    if (!std::is_sorted(column.begin(), column.end())) {
      return false;
    }
  }

  return true;
}

int main () {

  int tt{}; // Number of test cases.

  std::cin >> tt;

  for (int ii = 1; ii <= tt; ++ii) {

    int nn{}; // Size of the squared grid.

    std::cin >> nn;

    GridOfChar gg(nn);  // The grid.

    // Read the grid from stdin.
    for (int ii = 0; ii < nn; ++ii) {
      gg[ii].resize(nn);
      for (int jj = 0; jj < nn; ++jj) {
        std::cin >> gg[ii][jj];
      }
    }

    if (CanWeRearrangeAsDesired(gg)) {
      std::cout << R"(YES)" << std::endl;
    } else {
      std::cout << R"(NO)" << std::endl;
    }
  }
}
