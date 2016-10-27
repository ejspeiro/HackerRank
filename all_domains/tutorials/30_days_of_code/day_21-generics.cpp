#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printArray(std::vector<T> in) {
  for (const T &ee: in) {
    std::cout << ee << std::endl;
  }
}

int main() {

    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};

    printArray<int>(vInt);
    printArray<string>(vString);

    return 0;
}
