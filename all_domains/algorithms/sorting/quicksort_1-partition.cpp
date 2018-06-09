// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <vector>

template<typename TT>
int Partition(std::vector<TT> *aa, int ll, int hh) {
  int end_lower_region_idx = ll;
  TT pivot_elem = (*aa)[ll];

  for (int ii = ll + 1; ii <= hh; ++ii) {
    if ((*aa)[ii] <= pivot_elem) {
      ++end_lower_region_idx;
      std::swap((*aa)[ii], (*aa)[end_lower_region_idx]);
    }
  }
  std::swap((*aa)[end_lower_region_idx], (*aa)[ll]);
  return end_lower_region_idx;
}

int main() {
  int nn{};  // Number of elements.

  std::cin >> nn;

  std::vector<int> the_array(nn);
  for (int ii = 0; ii < nn; ii++) {
    std::cin >> the_array[ii];
  }

  int ll = 0;
  int hh = nn - 1;
  int pp = Partition(&the_array, ll, hh);

  for (int ii = 0; ii < nn; ii++) {
    std::cout << the_array[ii] << ' ';
  }
  std::cout << std::endl;
}
