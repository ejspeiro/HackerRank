#include <cmath>
#include <cstdio>

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int numTestCases = 0;
  cin >> numTestCases;
  cin.ignore();

  for (int ii = 1; ii <= numTestCases; ++ii) {
    string in;
    getline(cin, in);
    for (int jj = 0; jj < in.size(); jj = jj + 2) {
      cout << in.at(jj);
    }
    cout << ' ';
    for (int jj = 1; jj < in.size(); jj = jj + 2) {
      cout << in.at(jj);
    }
    cout << endl;
  }
}
