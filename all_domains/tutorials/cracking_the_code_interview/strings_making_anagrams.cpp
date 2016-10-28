#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
    
  std::unordered_map<char, int> count_a{};
  std::unordered_map<char, int> count_b{};
   
    for (int ii = 0; ii < a.length(); ++ii) {
        count_a[a[ii]]++;
    }
    for (int ii = 0; ii < b.length(); ++ii) {
        count_b[b[ii]]++;
    }
    int sum{};
    for (char ii = 'a'; ii <= 'z'; ++ii) {
      sum += abs(count_a[ii] - count_b[ii]);
    }
    return sum;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
