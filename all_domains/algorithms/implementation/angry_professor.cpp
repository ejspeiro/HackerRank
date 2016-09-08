#include <iostream>

using namespace std;

int main() {

  int numTestCases{};
  int nn{};
  int kk{};

  cin >> numTestCases;

  for (int ii = 0; ii < numTestCases; ++ii) {
    int aa{};
    int numPresent{};

    cin >> nn >> kk;
    for (int jj = 0; jj < nn; ++jj) {
      cin >> aa;
      numPresent += (aa <= 0)? 1: 0;
    }
    if (numPresent < kk) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
