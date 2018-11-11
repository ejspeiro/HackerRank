#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
  auto num_a_s = count(s.begin(), s.end(), 'a');
  long num_appends = n/s.length();
  long num_a_base = num_a_s*num_appends;
  for (size_t ii = 0; ii < n%s.length(); ++ii) {
    if (s.at(ii) == 'a') {
      num_a_base++;
    }
  }
  return num_a_base;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  string s;
  getline(cin, s);
  long n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  long result = repeatedString(s, n);
  fout << result << "\n";
  fout.close();
}
