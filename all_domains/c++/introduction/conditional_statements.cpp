#include <iostream>

int main () {
  
  int aa{}; // The number.
  
  std::cin >> aa;
  
  switch (aa) {
    case 1: {
      std::cout << "one" << std::endl;
      break;
    }
    case 2: {
      std::cout << "two" << std::endl;
      break;
    }
    case 3: {
      std::cout << "three" << std::endl;
      break;
    }
    case 4: {
      std::cout << "four" << std::endl;
      break;
    }
    case 5: {
      std::cout << "five" << std::endl;
      break;
    }
    case 6: {
      std::cout << "six" << std::endl;
      break;
    }
    case 7: {
      std::cout << "seven" << std::endl;
      break;
    }
    case 8: {
      std::cout << "eight" << std::endl;
      break;
    }
    case 9: {
      std::cout << "nine" << std::endl;
      break;
    }
    default: {
      std::cout << "Greater than 9" << std::endl;
      break;
    }
  }
}
