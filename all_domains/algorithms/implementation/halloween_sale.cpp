#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the howManyGames function below.
int howManyGames(int p, int d, int m, int s) {
  int num_games{};  // Number of games I can buy.
  if (s < p) {
    return num_games;
  }
  s -= p;
  num_games++;

  int new_game_price{p - d};  // Price of a game.
  if (s < new_game_price) {
    return num_games;
  }
  while (new_game_price >= m && s > new_game_price) {
    s -= new_game_price;
    num_games++;
    new_game_price -= d;
  }

  new_game_price = m;
  if (s < new_game_price) {
    return num_games;
  }
  while (s >= new_game_price) {
    s -= new_game_price;
    num_games++;
  }
  return num_games;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string pdms_temp;
    getline(cin, pdms_temp);
    vector<string> pdms = split_string(pdms_temp);
    int p = stoi(pdms[0]);
    int d = stoi(pdms[1]);
    int m = stoi(pdms[2]);
    int s = stoi(pdms[3]);

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";
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
