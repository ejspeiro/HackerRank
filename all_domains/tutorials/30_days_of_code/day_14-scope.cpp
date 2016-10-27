#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;

    public:
    int maximumDifference;

        Difference(vector<int> in): elements(in) {}

    void computeDifference() {
        maximumDifference = 0;
        for (int ii = 0; ii < elements.size(); ++ii) {
            for (int jj = 0; jj < elements.size(); ++jj) {
                int new_candidate = abs(elements[ii] - elements[jj]);
                if (new_candidate > maximumDifference) {
                    maximumDifference = new_candidate;
                }
            }
        }
    }

    }; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
