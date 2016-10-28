#include <cmath>

#include <iostream>
#include <iomanip>

#include <vector>

int main() {
  
  unsigned long nn{};
  unsigned long count{};
  
  std::cin >> nn;
  
  unsigned long count = 0ul;
  while(nn){
    count += nn%2ul? 0ul: 1ul;
    nn/=2ul; 
  }
  count = pow(2ul,count);
  
  std::cout << count << std::endl;
}
