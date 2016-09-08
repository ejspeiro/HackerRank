#include <iostream>

using namespace std;

int main() {

  int N;

  cin >> N;

  for (int ii = 1; ii <= 10; ++ii) {
    cout << N << " x " << ii << " = " << ii*N << endl;
  }
  cout << endl;
}
