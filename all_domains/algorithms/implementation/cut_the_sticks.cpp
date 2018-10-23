#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
  // Count lengths. Amortized O(n*log(n)).
  std::map<int, int> count_lengths{};

  for (int elem : arr) {
    if (count_lengths.find(elem) == count_lengths.cend()) {
      // Length not previously inserted before; insert.
      count_lengths.insert({elem, 1});
    } else {
      // Length previously inserted before; update.
      count_lengths.at(elem)++;
    }
  }

  // Compute total number of lengths given. O(1).
  int num_length = static_cast<int>(arr.size());

  // Compute the sum of all elements in the input array. O(n).
  int arr_sum = accumulate(arr.begin(), arr.end(), 0);

  // Prepare output array. O(1).
  vector<int> num_remaining_sticks{};

  // Subtract each length of the total sum computed. O(count_lengths.size()).
  map<int, int>::iterator next_min_length = count_lengths.begin();

  while (arr_sum > 0 or next_min_length != count_lengths.cend()) {
    num_remaining_sticks.push_back(num_length);

    int next_min_length_val = next_min_length->first;
    int next_min_length_count = next_min_length->second;

    arr_sum -= next_min_length_val*next_min_length_count;
    num_length -= next_min_length_count;
    next_min_length++;
  }
  return num_remaining_sticks;
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

    vector<int> result = cutTheSticks(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1) {
            fout << "\n";
        }
    }
    fout << "\n";
    fout.close();
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(),
                                      input_string.end(),
                                      [] (const char &x, const char &y) {
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
