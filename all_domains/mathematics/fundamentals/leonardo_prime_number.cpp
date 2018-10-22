#include <bits/stdc++.h>

using namespace std;

int pr[16] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

/*
 * Complete the primeCount function below.
 */
int primeCount(long n) {
    unsigned long long int x = 1;
    int i = 0;
    while ( x <= n  && i < 16 ) {
        x = x * pr[i];
        ++i;
    }
    return i - 1;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;

    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;

        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();
}
