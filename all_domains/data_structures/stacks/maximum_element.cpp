#include <cstdlib>

#include <iostream>

#include <stack>

int main () {

  int nn{}; // Number of queries.
  int qt{}; // Query type.
  int xx{}; // Integer for query type 1.

  std::cin >> nn;

  std::stack<int> ss;   // The stack.

  for (int qq = 1; qq <= nn; ++qq) {
    std::cin >> qt;
    switch (qt) {
      case 1: {
        std::cin >> xx;
        if (ss.empty()) {
          ss.push(xx);
        } else {
          ss.push(std::max(xx,ss.top()));
        }
        break;
      }
      case 2: {
        ss.pop();
        break;
      }
      case 3: {
        std::cout << ss.top() << std::endl;
        break;
      }
      default: {
        std::cerr << "Wrong query type." <<std::endl;
        return EXIT_FAILURE;
        break;
      }
    }
  }
}
