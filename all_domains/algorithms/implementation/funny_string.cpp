#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
  size_t left_idx{1};
  size_t right_idx{s.length() - 2};
  while (left_idx < s.length() &&
         abs(s.at(left_idx) - s.at(left_idx - 1)) ==
         abs(s.at(right_idx) - s.at(right_idx + 1))) {
    left_idx++;
    right_idx--;
  }
  if (left_idx == s.length()) {
    return "Funny";
  } else {
    return "Not Funny";
  }
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s;
    getline(cin, s);
    string result = funnyString(s);
    fout << result << "\n";
  }
  fout.close();
  return 0;
}
