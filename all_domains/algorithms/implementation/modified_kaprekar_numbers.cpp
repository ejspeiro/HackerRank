#include <bits/stdc++.h>

using namespace std;

bool IsModKap(int number) {
  long long original_number{number};

  // Count number of digits of input.
  int num_digits{};

  while (number > 0) {
    number /= 10;
    num_digits++;
  }

  // Square input number.
  long long number_squared{original_number*original_number};

  // Compute rigth number.
  int right{};
  int counter{};
  while (counter < num_digits) {
    right += (number_squared%10)*pow(10, counter);
    number_squared /= 10;
    counter++;
  }

  // Compute left number.
  int left{};
  counter = 0;
  while (number_squared > 0) {
    left += (number_squared%10)*pow(10, counter);
    number_squared /= 10;
    counter++;
  }

  return (right + left == original_number);
}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
  bool invalid_range{true};

  for (int nn = p; nn <= q; ++nn) {
    if (IsModKap(nn)) {
      invalid_range = false;
      cout << nn << ' ';
    }
  }
  if (invalid_range) {
    cout << "INVALID RANGE";
  }
  cout << endl;
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
