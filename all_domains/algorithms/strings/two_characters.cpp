#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
  constexpr size_t kNumLetters{26};
  array<array<char, kNumLetters>, kNumLetters> letters{};
  array<array<int, kNumLetters>, kNumLetters> lengthString{};

  for(char c : s) {
    int index = (int)(c - 'a');
    for(int i = 0; i < kNumLetters; i++) {
      if(letters[index][i] != c && lengthString[index][i] != -1) {
          letters[index][i] = c;
          ++lengthString[index][i];
      } else {
          lengthString[index][i] = -1;
      }
      if(letters[i][index] != c && lengthString[i][index] != -1) {
          letters[i][index] = c;
          ++lengthString[i][index];
      } else {
          lengthString[i][index] = -1;
      }
    }
  }
  int largestString = 0;
  for(int i = 0; i < kNumLetters; i++) {
      for(int j = 0; j < kNumLetters; j++) {
          if(lengthString[i][j] > largestString) {
              largestString = lengthString[i][j];
          }
      }
  }
  if(largestString > 1) {
      return largestString;
  } else {
      return 0;
  }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string l_temp;
    getline(cin, l_temp);
    int l = stoi(ltrim(rtrim(l_temp)));
    string s;
    getline(cin, s);
    int result = alternate(s);
    fout << result << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
