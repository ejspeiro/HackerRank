// Code style adapted to fit HackerRank's preexisting code in this exercise.

#include <cstdio>
#include <cmath>

#include <iostream>

#include <vector>

#include <algorithm>

int main() {

  float mealCost = 0.0f;
  float tipPercent = 0.0f;
  float taxPercent = 0.0f;

  std::cin >> mealCost;
  std::cin >> tipPercent;
  std::cin >> taxPercent;

  float totalCost = round(mealCost + mealCost*(tipPercent/100.0f) +
    mealCost*(taxPercent/100.0f));

  std::cout << "The total meal cost is " << totalCost << " dollars." <<
    std::endl;
}
