#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long getWays_dp(vector<long> S, size_t m, long n) {
  long i, j, x, y;

  // We need n+1 rows as the table
  // is constructed in bottom up
  // manner using the base case 0
  // value case (n = 0)
  long table[n + 1][m];

  // Fill the enteries for 0
  // value case (n = 0)
  for (i = 0; i < m; i++)
      table[0][i] = 1;

  // Fill rest of the table entries
  // in bottom up manner
  for (i = 1; i < n + 1; i++)
  {
      for (j = 0; j < m; j++)
      {
          // Count of solutions including S[j]
          x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;

          // Count of solutions excluding S[j]
          y = (j >= 1) ? table[i][j - 1] : 0;

          // total count
          table[i][j] = x + y;
      }
  }
  return table[n][m - 1];
}

// Complete the getWays function below.
long getWays(long n, vector<long> c) {
  return getWays_dp(c, c.size(), n);
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  string nm_temp;
  getline(cin, nm_temp);
  vector<string> nm = split_string(nm_temp);
  int n = stoi(nm[0]);
  int m = stoi(nm[1]);
  string c_temp_temp;
  getline(cin, c_temp_temp);
  vector<string> c_temp = split_string(c_temp_temp);
  vector<long> c(m);
  for (int i = 0; i < m; i++) {
    long c_item = stol(c_temp[i]);
    c[i] = c_item;
  }
  // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
  long ways = getWays(n, c);
  fout << ways << endl;
  fout.close();
  return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    while (input_string[input_string.length() - 1] == ' ') {
      input_string.pop_back();
    }
    vector<string> splits;
    char delimiter = ' ';
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    while (pos != string::npos) {
      splits.push_back(input_string.substr(i, pos - i));
      i = pos + 1;
      pos = input_string.find(delimiter, i);
    }
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    return splits;
}
