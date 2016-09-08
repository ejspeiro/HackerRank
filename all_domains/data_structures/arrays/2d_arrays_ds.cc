#include <iostream>

#include <vector>
#include <queue>

typedef std::vector< std::vector<int> > Matrix;

int SumHourglassAt(Matrix aa, int ii, int jj) {

  return aa[ii - 1][jj - 1] + aa[ii - 1][jj + 0] + aa[ii - 1][jj + 1] +
                              aa[ii + 0][jj + 0] +
         aa[ii + 1][jj - 1] + aa[ii + 1][jj + 0] + aa[ii + 1][jj + 1];
}

int main() {

  const int rank = 6;
  std::vector< std::vector<int> > arr(rank, std::vector<int>(rank));

  // Read input matrix.
  for(int arr_i = 0; arr_i < rank; ++arr_i){
    for(int arr_j = 0; arr_j < rank; ++arr_j){
      std::cin >> arr[arr_i][arr_j];
    }
  }

  // Per each hourglass, compute the sum of its values.
  std::priority_queue<int> qq;
  for (int ii = 1; ii < rank - 1; ++ii) {
    for (int jj = 1; jj < rank - 1; ++jj) {
      qq.push(SumHourglassAt(arr, ii, jj));
    }
  }
  std::cout << qq.top() << std::endl;
}
