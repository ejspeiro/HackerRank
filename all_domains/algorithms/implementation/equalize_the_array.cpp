#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {
  map<int, int> counter{};

  for (int elem : arr) {
    if (counter.find(elem) == counter.cend()) {
      counter.insert({elem, 1});
    } else {
      counter.at(elem)++;
    }
  }

  map<int, int>::const_iterator greatestIt{};
  int maxElement{};
  for (map<int, int>::const_iterator elemIt = counter.cbegin();
       elemIt != counter.cend(); ++elemIt) {
    if (elemIt->second > maxElement) {
      maxElement = elemIt->second;
      greatestIt = elemIt;
    }
  }

  int countElements{};
  map<int, int>::const_iterator counterIt{};

  for (counterIt = counter.cbegin();
       counterIt != counter.cend(); ++counterIt) {
    if (counterIt != greatestIt) {
      countElements += counterIt->second;
    }
  }
  return countElements;
}

int main()
{
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

    int result = equalizeArray(arr);

    fout << result << "\n";

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
