// Copyright 2017 Eduardo Sanchez.
#include <iostream>
#include <valarray>

int main() {

  int nn{};  // Number of values.

  std::cin >> nn;

  std::valarray<float> values(nn);  // Value array of values.
  std::valarray<float> weights(nn);  // Value array of weights.

  for (int ii = 0; ii < nn; ++ii) {
    float aux{};
    std::cin >> aux;
    values[ii] = aux;
  }
  for (int ii = 0; ii < nn; ++ii) {
    float aux{};
    std::cin >> aux;
    weights[ii] = aux;
  }

  std::valarray<float> numeratorArray = weights*values;
  float numerator = numeratorArray.sum();
  float denominator = weights.sum();

  std::cout.setf(std::ios::fixed);
  std::cout.precision(1);
  std::cout << numerator/denominator << std::endl;
}
