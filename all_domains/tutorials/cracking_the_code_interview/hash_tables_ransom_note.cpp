// Copyright 2018 Eduardo Sanchez
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

bool ransom_note(std::vector<std::string> magazine,
                 std::vector<std::string> ransom) {
    std::sort(magazine.begin(), magazine.end());
    std::sort(ransom.begin(), ransom.end());
    return std::includes(magazine.begin(),
                         magazine.end(),
                         ransom.begin(),
                         ransom.end());
}

int main() {
    int m;
    int n;

    std::cin >> m >> n;

    std::vector<std::string> magazine(m);

    for (int magazine_i = 0; magazine_i < m; ++magazine_i) {
       std::cin >> magazine[magazine_i];
    }

    std::vector<std::string> ransom(n);

    for (int ransom_i = 0; ransom_i < n; ++ransom_i) {
       std::cin >> ransom[ransom_i];
    }
    if (ransom_note(magazine, ransom)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
