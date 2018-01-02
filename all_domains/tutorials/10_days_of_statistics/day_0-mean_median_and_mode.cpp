// Copyright 2017 Eduardo Sanchez.
#include <iostream>
#include <algorithm>
#include <valarray>
#include <limits>
#include <utility>
#include <unordered_map>

int main() {
  size_t nn{};  // Number of elements in the array.

  std::cin >> nn;

  std::valarray<float> numArray(nn);  // Array to hold the values.

  for (size_t ii = 0; ii < nn; ++ii) {
    float tmp{};  // Temporary floating-point variable for input.
    std::cin >> tmp;
    numArray[ii] = tmp;
  }

  // Compute the mean of the array.

  // This can be done in O(nn). If the problem did not include computing the
  // mean (which requires a partial sorting), we could have just add the values
  // while reading them, and divide said sum by a count of the read values, thus
  // solving the mean in constant memory and linear complexity.

  float mean{};  // Mean of the collection of values.

  mean = numArray.sum()/static_cast<float>(nn);

  std::cout << mean << std::endl;

  // Compute the median of the array. Linear complexity.

  // nth_element is a partial sorting algorithm that rearranges elements in
  // [first, last) such that:
  // 1. The element pointed at by nth is changed to whatever element would
  // occur in that position if [first, last) was sorted.
  // 2. All of the elements before this new nth element are less than or equal
  // to the elements after the new nth element.
  // Linear in std::distance(first, last) on average.
  // The algorithm used is typically introselect although other selection
  // algorithms with suitable average-case complexity are allowed.

  // Note that valarray objects have no member function begin defined nor have
  // iterator member types: The iterator returned is a random-access iterator of
  // an unspecified type whose value_type is T and its reference type is T& for
  // (1) and const T& for (2) (it is a mutable iterator for (1), and a constant
  // iterator for (2)).

  float median{};  // Median of the values.

  if (nn%2 == 0) {
    // nn is even. Return the average of the 2 values in the center.
    std::nth_element(begin(numArray),
                     begin(numArray) + numArray.size()/2 - 1,
                     end(numArray));
    median = (numArray[numArray.size()/2] +
              numArray[numArray.size()/2 - 1])/2.0;
  } else {
    // nn is odd. Proceed with the median.
    std::nth_element(begin(numArray),
                     begin(numArray) + numArray.size()/2,
                     end(numArray));
    median = numArray[numArray.size()/2];
  }

  std::cout << median << std::endl;

  // Compute the modes of the array. Linear complexity.

  std::unordered_map<float, int> modes{};  // Map of values to appearances.

  // Count number of appereances of each element. Linear complexity.
  for (float val : numArray) {
    if (modes.find(val) != modes.cend()) {
      modes.at(val)++;
    } else {
      modes.insert(std::make_pair(val, 1));
    }
  }

  // Detect if there are different numbers of appereances. Linear complexity.
  auto minElem = std::min_element(modes.begin(),
                                  modes.end(),
                                  [] (std::pair<float, int> aa,
                                      std::pair<float, int> bb) {
                                        return aa.second < bb.second;
                                      });
  auto maxElem = std::max_element(modes.begin(),
                                  modes.end(),
                                  [] (std::pair<float, int> aa,
                                      std::pair<float, int> bb) {
                                        return aa.second < bb.second;
                                      });
  if (minElem->second == maxElem->second) {
    // All the values have the same number of appereances. Choose the smallest.
    float minValue{std::min_element(modes.begin(), modes.end())->first};
    std::cout << minValue << std::endl;
  } else {
    // Values have different appereances.
    // Compute the highest number of appereances.
    int maxNumAppears = maxElem->second;
    // Find smallest key with value equal to maxNumAppears. Linear complexity.
    float minValue{std::numeric_limits<float>::max()};
    for (const auto &keyValue : modes) {
      if (keyValue.second == maxNumAppears && keyValue.first < minValue) {
        minValue = keyValue.first;
      }
    }
    std::cout << minValue << std::endl;
  }
}
