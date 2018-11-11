#include <iostream>
#include <numeric>

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
  constexpr int kYearLateFee{10000};
  constexpr int kBaseMonthlyLateFee{500};
  constexpr int kBaseDailyLateFee{15};
  constexpr int kNoFee{};

  if (y1 > y2) {
    // Return year is 1 or more years after the due year.
    return kYearLateFee;
  } else if (y1 == y2) {
    // Return year is the same as due year.
    if (m1 > m2) {
      // Return month is 1 or more months after the due month in the same year.
      return kBaseMonthlyLateFee*(m1 - m2);
    } else if (m1 == m2) {
      // Return month is the same as due month in the same year.
      if (d1 > d2) {
        return kBaseDailyLateFee*(d1 - d2);
      }
    }
  }
  // Return year is before the due year.
  return kNoFee;
}

int main() {
  int d_return{};
  int m_return{};
  int y_return{};
  int d_due{};
  int m_due{};
  int y_due{};

  std::cin >> d_return >> m_return >> y_return;
  std::cin >> d_due >> m_due >> y_due;
  std::cout << libraryFine(d_return, m_return, y_return,
                           d_due, m_due, y_due) << std::endl;
}
