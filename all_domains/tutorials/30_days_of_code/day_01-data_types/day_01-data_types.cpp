// Code style adapted to fit HackerRank's preexisting code in this exercise.

#include <iostream>
#include <iomanip>
#include <limits>

int main() {

  double d{4.0};

  int i{4};

  std::string s = "HackerRank ";

  // Declare second integer, double, and String variables.
  int j{};

  double e{};

  std::string t{};

  // Read and save an integer, double, and String to your variables.
  std::cin >> j;
  std::cin >> e;
  std::cin.ignore();
  getline(std::cin, t);

  // Print the sum of both integer variables on a new line.
  std::cout << i + j << std::endl;

  // Print the sum of the double variables on a new line.
  std::cout.precision(1);
  std::cout << fixed << d + e << std::endl;

  // Concatenate and print the String variables on a new line
  // The 's' variable above should be printed first.
  std::cout << s + t << std::endl;
}
