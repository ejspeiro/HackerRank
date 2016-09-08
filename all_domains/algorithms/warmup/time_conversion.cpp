#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string hour{};

  getline(cin, hour);

  istringstream inputString(hour.substr(0,2));
  int hh{};
  inputString >> hh;

  if (hour.at(8) == 'A') {
    if (hh == 12) {
      cout << "00:" << hour.substr(3,hour.size() - 5) << endl;
    } else {
      cout << hour.substr(0,hour.size() - 2) << endl;
    }
  } else {
    if (hh == 12) {
      cout << "12:" << hour.substr(3,hour.size() - 5) << endl;
    } else {
      cout << hh + 12 << ':' << hour.substr(3,hour.size() - 5) << endl;
    }
  }
}
