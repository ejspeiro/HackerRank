// Copyright 2018 Eduardo Sanchez
#include <iostream>

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <>
struct Traits <Color> {
  static std::string name(int index) {
    switch (index) {
      case 0: {
        return "red";
        break;
      }
      case 1: {
        return "green";
        break;
      }
      case 2: {
        return "orange";
        break;
      }
      default: {
        return "unknown";
        break;
      }
    }
  }
};

template <>
struct Traits <Fruit> {
  static std::string name(int index) {
    switch (index) {
      case 0: {
        return "apple";
        break;
      }
      case 2: {
        return "pear";
        break;
      }
      case 1: {
        return "orange";
        break;
      }
      default: {
        return "unknown";
        break;
      }
    }
  }
};

int main() {
  int t = 0;  // Number of test case.

  std::cin >> t;
  for (int i = 0; i != t; ++i) {
    int index1;  // Read integer.
    int index2;  // Read integer.

    std::cin >> index1;
    std::cin >> index2;
    cout << Traits<Color>::name(index1) << " ";
    cout << Traits<Fruit>::name(index2) << "\n";
  }
}
