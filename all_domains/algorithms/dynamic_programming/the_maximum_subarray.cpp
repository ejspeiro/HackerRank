#include <iostream> // For std::cout.

#include <vector>   // For std::vector<>.

// Function template to find the one-past-end pointer to the array
template<typename T, int N>
int *end(T (&arr)[N]) {

  return arr + N;
}

int MaxSumSubarrays(const std::vector<int> &aa) {

  int max_ending_here = 0;
  int max_so_far = 0;

  for (int xx: aa) {

  }
}

int main () {

  int tt{}; // Number of test cases.

  std::cin >> tt;

  for (int cc = 1; cc <= tt; ++cc) {

    int nn{}; // Number of elements in this array.

    std::cin >> nn;

    std::vector<int> aa(nn);  // The array.

    for (int ii = 0; ii < nn; ++ii) {
      std::cin >> aa[ii];
    }


  }
}
