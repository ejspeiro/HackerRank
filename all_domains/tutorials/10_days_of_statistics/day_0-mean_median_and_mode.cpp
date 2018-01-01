#include <iostream>
#include <algorithm>
#include <valarray>
#include <unordered_map>

int main () {

  size_t nn{}; // Number of elements in the array.

  std::cin >> nn;

  std::valarray<float> numArray(nn); // Array to hold the values.

  for (size_t ii = 0; ii < nn; ++ii) {
    float tmp{}; // Temporary floating-point variable for input.
    std::cin >> tmp;
    numArray[ii] = tmp;
  }

  // Compute the mean of the array.

  // This can be done in O(nn). If the problem did not include computkng the
  // mean (which requires a partial sorting), we could have just add the values
  // while reading them, and divide said sum by a count of the read values, thus
  // solving the mean in constant memory and linear complexity.
  float mean{};

  mean = numArray.sum()/static_cast<float>(nn);

  std::cout << mean << std::endl;

  // Compute the median of the array.

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

  float median{}; // Median of the values.

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

  // Compute the modes of the array.

  // An unordered_map stores key-value pairs with no order. Retrieval based on
  // a given key happens in constant time. We can keep an unordered_map of each
  // value and its occurrence to then check in linear time if the maximum
  // number of appereances is not unique.

  std::unordered_map<float, int> modes(nn); // UMap of values to appearances.

  for (const float val: numArray) {
    if (modes.find(val) != modes.cend()) {
      modes.at(val)++;
    } else {
      modes.insert(std::make_pair(val, 1));
    }
  }

  for (const auto &mode: modes) {
    std::cout << mode.first << " : " << mode.second << std::endl;
  }

  auto minElem = std::min_element(modes.begin(), modes.end());
  auto maxElem = std::max_element(modes.begin(), modes.end());

  std::cout << (*minElem).first << std::endl;
  std::cout << (*maxElem).first << std::endl;
}
