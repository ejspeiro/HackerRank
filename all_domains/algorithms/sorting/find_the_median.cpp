// Copyright 2018 Eduardo Sanchez
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::ofstream;
using std::streamsize;
using std::min;
using std::vector;
using std::string;
using std::numeric_limits;

vector<string> split_string(string);

// Complete the findMedian function below.
int findMedian(vector<int> arr) {
  float median{};  // Median of the values.

  if (arr.size()%2 == 0) {
    // nn is even. Return the average of the 2 values in the center.
    std::nth_element(arr.begin(),
                     arr.begin() + arr.size()/2 - 1,
                     arr.end());
    median = (arr[arr.size()/2] +
              arr[arr.size()/2 - 1])/2.0;
  } else {
    // nn is odd. Proceed with the median.
    std::nth_element(arr.begin(),
                     arr.begin() + arr.size()/2,
                     arr.end());
    median = arr[arr.size()/2];
  }

  return static_cast<int>(median);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = findMedian(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(),
                                      input_string.end(),
                                      [] (const char &x, const char &y) {
                                        return x == y && x == ' ';
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

    auto tmp = min(pos, input_string.length()) - i + 1;
    splits.push_back(input_string.substr(i, tmp));

    return splits;
}
