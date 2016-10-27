#include <iostream>

#include <vector>

void Print(const std::vector<int> &aa, int ll, int hh) {

  for (int ii = ll; ii <= hh; ++ii) {
    std::cout << aa[ii] << ' ';
  }
  std::cout << std::endl;
}

int Partition(std::vector<int> &aa, int ll, int hh) {

  int ii;
  int pp;
  int first_high;

  pp = hh;
  first_high = ll;
  for (ii = ll; ii < hh; ii++) {
    if (aa[ii] < aa[pp]) {
      std::swap(aa[ii], aa[first_high]);
      first_high++;
    }
  }
  std::swap(aa[pp], aa[first_high]);
  return first_high;
}

void QuickSort(std::vector<int> &aa, int ll, int hh) {

  int pp{};

  if ((hh - ll) > 0) {
    pp = Partition(aa, ll, hh);
    Print(aa, 0, aa.size() - 1);
    QuickSort(aa, ll, pp - 1);
    QuickSort(aa, pp + 1, hh);
  }
}



int main() {

  int nn{};

  std::cin >> nn;

  std::vector<int> the_array(nn);

  for (int ii = 0; ii < nn; ii++) {
    std::cin >> the_array[ii];
  }

  int ll = 0;
  int hh = nn - 1;

  QuickSort(the_array, ll, hh);
}
