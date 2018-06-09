// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <map>

int32_t GetRankForScore(int32_t ss, const std::map<int32_t, int32_t> &lb) {
  auto ss_pos = lb.upper_bound(ss);

  if (ss_pos != lb.end()) {
    return ss_pos->second + 1;
  } else {
    return 1ul;
  }
}

int main() {
  int32_t nn{};  // Number of scores.

  std::cin >> nn;

  // Hash map of scores and their rank.
  std::map<int32_t, int32_t> leader_board{};
  int32_t rank{1};  // First rank.

  for (auto ii = 0ul; ii < nn; ++ii) {
    int32_t score{};  // Current score.
    std::cin >> score;
    if (leader_board.find(score) == leader_board.end()) {
      // Score has not been added.
      leader_board.insert({score, rank});
      ++rank;
    }
  }
  // for (auto item: leader_board) {
  //   std::cout << item.first << ' ' << item.second << std::endl;
  // }

  int32_t mm{};  // Number of queries.

  std::cin >> mm;
  for (auto ii = 0ul; ii < mm; ++ii) {
    int32_t qq{};  // Query.

    std::cin >> qq;
    std::cout << GetRankForScore(qq, leader_board) << std::endl;
  }

  // Exploration of special search methods for std::map<>.

  // std::map<int, int> a_map{};
  //
  // a_map.insert({10, 5});
  // a_map.insert({20, 4});
  // a_map.insert({40, 3});
  // a_map.insert({50, 2});
  // a_map.insert({100, 1});
  //
  // for (auto item: a_map) {
  //   std::cout << item.first << ' ' << item.second << std::endl;
  // }
  // std::cout << std::endl;
  //
  // std::map<int, int>::iterator it_low = a_map.lower_bound(40);
  // std::map<int, int>::iterator it_upp = a_map.upper_bound(40);
  //
  // std::cout << it_low->first << ' ' << it_low->second << std::endl;
  // std::cout << it_upp->first << ' ' << it_upp->second << std::endl;
}
