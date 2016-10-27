#include <iostream>

#include <vector>

bool Compare (int aa, int bb) { return aa < bb;}

// Insertion sort algorithm.
// Implementation:  ITERATIVE.
// Adaptive?        YES.
// Stable?          YES.
// Online?          YES.
// W(n) =           O(n^2).
// A(n) =           Θ(n^2).
// B(n) =           Ω(n).
// In-Place?        YES.
// W(s) =           O(1).
// From Sedgewick, Robert (1983), Algorithms, Addison-Wesley, pp. 95:
// "When people manually sort cards in a bridge hand, most use a method that is
// similar to insertion sort".
// Insertion sort is particularly significant as the algorithm which minimizes
// the amount of data movement. Since an almost-sorted permutation has few
// inversions, insertion sort can be very effective on such data.
void InsertionSort(std::vector<int> &aa) {

  // For every element starting from the second one...
  for (int ii = 1; ii < aa.size(); ++ii) {
    int cc = ii;
    while (cc > 0 && Compare(aa[cc], aa[cc - 1])) {
      std::swap(aa[cc], aa[cc - 1]);
      cc--;
    }

    for (const int &ee: aa) {
      std::cout << ee << ' ';
    }
    std::cout << std::endl;
  }
}

int main () {

  int nn = int();   // Size of the array.

  std::cin >> nn;

  std::vector<int> the_array(nn);   // Array to sort.

  for (int ii = 0; ii < nn; ++ii) {
    std::cin >> the_array.at(ii);
  }

  InsertionSort(the_array);
}
