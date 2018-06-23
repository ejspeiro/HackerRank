// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>

class Server {
 private:
  static int load;
 public:
  static int compute(int64_t A, int64_t B) {
    load += 1;
    if (A < 0) {
      throw std::invalid_argument("A is negative");
    }
    std::vector<int> v(A, 0);
    int real = -1, cmplx = sqrt(-1);
    if (B == 0) {
      throw 0;
    }
    real = (A/B)*real;
    int ans = v.at(B);
    return real + A - B*ans;
  }
  static int getLoad() {
    return load;
  }
};

int Server::load = 0;

int main() {
  int T;

  std::cin >> T;
  while (T--) {
    int64_t A, B;

    std::cin >> A >> B;
    int computation{};  // Computation result.
    try {
      computation = Server::compute(A, B);
      std::cout << computation << std::endl;
    } catch (const std::bad_alloc &ee) {
      std::cout << "Not enough memory" << std::endl;
    } catch (const std::exception &ee) {
      std::cout << "Exception: " << ee.what() << std::endl;
    } catch (...) {
      std::cout << "Other Exception" << std::endl;
    }
  }
  std::cout << Server::getLoad() << std::endl;
}
