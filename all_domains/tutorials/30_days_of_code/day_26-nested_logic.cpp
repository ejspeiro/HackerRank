#include <iostream>

int main () {

  int ad{}; // Actual day.
  int am{}; // Actual month.
  int ay{}; // Actual year.

  int ed{}; // Expected day.
  int em{}; // Expected month.
  int ey{}; // Expected year.

  int fine{};

  std::cin >> ad >> am >> ay;
  std::cin >> ed >> em >> ey;

  if (ay > ey) {
    fine += 10000;
  } else if (ay == ey) {
    if (am > em) {
      fine += 500*(am - em);
    } else if (am == em) {
      if (ad > ed) {
        fine += 15*(ad - ed);
      }
    }
  }

  std::cout << fine << std::endl;
}
