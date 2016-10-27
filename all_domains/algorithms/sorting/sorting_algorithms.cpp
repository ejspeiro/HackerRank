#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Let n be a problem size, and s = s(n) the required memory space, for a
// problem of size n.

// First, we define the following important concepts:

// Def. Adaptive sorting algorithm. A sorting algorithm falls into the adaptive
// sort family if it takes advantage of existing order in its input.

// Def. Stable sorting algorithm. A sorting algorithm is said to be stable if
// two objects with equal keys appear in the same order in sorted output as they
// appear in the input array to be sorted.

// Def. Online sorting algorithm. An online sorting algorithm is one that can
// only process its input piece-by-piece in a serial fashion, i.e., in the order
// that the input is fed to the algorithm, without having the entire input
// available from the start.

// Def. In-place sorting algorithm. An in-place sorting algorithm is an
// algorithm which sorts input using no auxiliary data structure. That is W(s)
// is in O(1).

// We now define the comparison routine which will be used to sort the array.

bool Compare (int aa, int bb) { return aa < bb;}

// Bubble sort algorithm.
// Implementation:  ITERATIVE.
// Adaptive?        YES.
// Stable?          YES.
// Online?          NO.
// W(n) =           O(n^2).
// A(n) =           Θ(n^2).
// B(n) =           Ω(n).
// In-Place?        YES.
// W(s) =           O(1).
void BubbleSort(std::vector<int> &aa) {

  // For each element in the array...
  for (int ii = 0; ii < aa.size(); ++ii) {
    // Compare against each of the subsequent elements in the array.
    for (int jj = 0; jj < aa.size(); ++jj) {
      if (Compare(aa[ii], aa[jj])) {
        std::swap(aa[ii], aa[jj]);
      }
    }
  }
}

// Selection sort algorithm.
// Implementation:  ITERATIVE.
// Adaptive?        YES.
// Stable?          YES.
// Online?          NO.
// W(n) =           O(n^2).
// A(n) =           Θ(n^2).
// B(n) =           Ω(n).
// In-Place?        YES.
// W(s) =           O(1).
void SelectionSort(std::vector<int> &aa) {

  // For each element in the array...
  for (int ii = 0; ii < aa.size(); ++ii) {
    // Assume the ii-th element is the minimum element in the array.
    int min = ii;   // index of the minimum element in the sorted array.
    // Compare against each of the subsequent elements to determine real min.
    for (int jj = ii + 1; jj < aa.size(); ++jj) {
      if (Compare(aa[jj], aa[min])) {
        std::swap(aa[jj], aa[min]);
      }
    }
  }
}

// Here we finish the two simplest sorting algorithms. We now turn into another
// pair of algorithms that are related.

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
  }
}

// Shell sort algorithm.
// Implementation:  ITERATIVE.
// Adaptive?        YES.
// Stable?          NO.
// Online?          NO.
// W(n) =           O(n^2).
// A(n) =           Depends of the gap sequence. Best known is is Θ(n*log(n)^2).
// B(n) =           Ω(n*log(n)^2).
// In-Place?        YES.
// W(s) =           O(1).
// Donald Shell published the first version of this sort in 1959.
// Shell sort is a generalization of insertion sort that allows the exchange of
// items that are far apart.
void ShellSort(std::vector<int> &aa) {

  // We use Marcin Ciura's gap sequence, with an inner insertion sort.
  int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
  constexpr int num_gaps{8};
  int jj{};

  for (int gap = 0; gap < num_gaps; ++gap) {
    int gg = gaps[gap];
    for (int ii = gg; ii < aa.size(); ++ii) {
      int tt = aa[ii];
      for (jj = ii; jj >= gg && aa[jj - gg] > tt; jj -= gg) {
        aa[jj] = aa[jj - gg];
      }
      aa[jj] = tt;
    }
  }
}

// At this point the "simple" sorting algorithms have been covered. We now
// proceed to study algorithms that are actually used in practice, and that are
// actually the underlying foundations of those which can be found in standard
// libraries.

// Heap sort algorithm.
// Implementation:  ITERATIVE.
// Adaptive?        NO.
// Stable?          NO.
// Online?          YES.
// W(n) =           O(n*log(n)).
// A(n) =           O(n*log(n)).
// B(n) =           Ω(n).
// In-Place?        YES.
// W(s) =           O(1).
void HeapSort(std::vector<int> &aa) {

  std::priority_queue<int> heap;

  for (int ii = 0; ii < aa.size(); ++ii) {
    heap.push(aa[ii]);
  }
  for (int ii = 0; ii < aa.size(); ++ii) {
    aa[ii] = heap.top();
    heap.pop();
  }
}

// Quick sort algorithm.
// Implementation:  RECURSIVE.
// Adaptive?        NO.
// Stable?          NO.
// Online?          NO.
// W(n) =           O(n^2).
// A(n) =           O(n*log(n)).
// B(n) =           Ω(n*log(n)) (simple partition).
// In-Place?        YES.
// W(s) =           O(1).
// Quick sort is often faster in practice than other Ω(n*log(n)) algorithms.
// Additionally, Quick sort's sequential and localized memory references work
// well within a cache.
// It is not efficient is the sub arrays are smaller... in this case:
// Insertion sort!
int Partition(std::vector<int> &aa, int ll, int hh);

void QuickSort(std::vector<int> &aa, int ll, int hh) {

  int pp{};

  if ((hh - ll) > 0) {
    pp = Partition(aa, ll, hh);
    QuickSort(aa, ll, pp - 1);
    QuickSort(aa, pp + 1, hh);
  }
}

// Lomuto partition scheme.
// This scheme chooses a pivot which is typically the last element in the array.
// The algorithm maintains the index to put the pivot in variable i and each
// time it finds an element less than or equal to pivot, this index is
// incremented and that element would be placed before the pivot. As this scheme
// is more compact and easy to understand, it is frequently used in introductory
// material, although it is less efficient than Hoare's original scheme.
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

//  In cstdlib... we find:

// void qsort(void *array, size_t count, size_t size, comparison_fn_t compare);

// The qsort function sorts the array array. The array contains count elements,
// each of which is of size size. The compare function is used to perform the
// comparison on the array elements. This function is called with two pointer
// arguments and should return an integer less than, equal to, or greater than
// zero corresponding to whether its first argument is considered less than,
// equal to, or greater than its second argument.

// Introspective sort algorithm.
// Implementation:  RECURSIVE.
// Adaptive?        NO.
// Stable?          NO.
// Online?          YES.
// W(n) =           O(n*log(n)).
// A(n) =           O(n*log(n)).
// B(n) =           Ω(n).
// In-Place?        YES.
// W(s) =           O(1).
void IntrospectiveSortCore(std::vector<int> &aa, int maxdepth, int ll, int hh);

void IntrospectiveSort(std::vector<int> &aa, int ll, int hh) {

  int nn = static_cast<int>(aa.size());
  int maxdepth = static_cast<int>(floor(log(static_cast<double>(nn)))*2);
  IntrospectiveSortCore(aa, maxdepth, ll, hh);
}

void IntrospectiveSortCore(std::vector<int> &aa, int maxdepth, int ll, int hh) {

  int nn = hh - ll - 1;
  int pp;

  if (nn <= 1) {
    return;
  } else if (maxdepth == 0) {
    HeapSort(aa);
  } else {
    pp = Partition(aa, ll, hh);
    IntrospectiveSortCore(aa, maxdepth - 1, ll, pp - 1);
    IntrospectiveSortCore(aa, maxdepth - 1, pp + 1, hh);
  }
}



std::vector<int> Merge(std::vector<int> &vec,
                       const std::vector<int> &left,
                       const std::vector<int> &right);

std::vector<int> MergeSort(std::vector<int> aa) {

  if (aa.size() == 1) {
    return aa;
  }

  std::vector<int>::iterator middle = aa.begin() + (aa.size()/2);
  std::vector<int> left(aa.begin(), middle);
  std::vector<int> right(middle, aa.end());

  left = MergeSort(left);
  right = MergeSort(right);
  return Merge(aa, left, right);
}

// Fills the resultant vector with sorted results from both vectors.
std::vector<int> Merge(std::vector<int> &vec,
                       const std::vector<int> &left,
                       const std::vector<int> &right) {

  std::vector<int> result;

  size_t left_it{};
  size_t right_it{};

  while (left_it < left.size() && right_it < right.size()) {
    // If the left value is smaller than the right it goes next into the result.
    if (left[left_it] < right[right_it]) {
      result.push_back(left[left_it]);
      left_it++;
    } else {
      result.push_back(right[right_it]);
      right_it++;
    }
  }
  // Push the remaining data from both vector onto the resultant.
  while (left_it < left.size()) {
    result.push_back(left[left_it]);
    left_it++;
  }
  while (right_it < right.size()) {
    result.push_back(right[right_it]);
    right_it++;
  }

  return result;
}

int main () {

  std::vector<int> aa(6);
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  BubbleSort(aa);

  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << std::endl;
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  SelectionSort(aa);

  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << std::endl;
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  InsertionSort(aa);

  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << std::endl;
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  ShellSort(aa);

  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << std::endl;
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  QuickSort(aa, 0, static_cast<int>(aa.size()) - 1);

  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << std::endl;
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  HeapSort(aa);

  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << std::endl;
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  IntrospectiveSort(aa, 0, static_cast<int>(aa.size()) - 1);

  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << std::endl;
  for (int &ee: aa) {ee = drand48()*100;}
  for (const int &ee: aa) {std::cout << ee << ' ';} std::cout << R"( - )";

  aa = MergeSort(aa);

  for (const int &ee: aa) {std::cout << ee << ' ';}
  std::cout << std::endl;
}
