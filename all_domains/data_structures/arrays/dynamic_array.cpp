#include <cstdlib>

#include <iostream>

#include <vector>

void PerformQuery1(std::vector<std::vector<unsigned long int>> &seqList,
                   unsigned long int lastAns,
                   unsigned long int xx,
                   unsigned long int yy) {

  auto nn = seqList.size();
  auto index = (xx ^ lastAns)%nn;
  seqList.at(index).push_back(yy);
}

void PerformQuery2(std::vector<std::vector<unsigned long int>> &seqList,
                   unsigned long int &lastAns,
                   unsigned long int xx,
                   unsigned long int yy) {

  auto nn = seqList.size();
  auto index = (xx ^ lastAns)%nn;
  auto sizee = seqList.at(index).size();
  auto other_index = yy%sizee;
  lastAns = seqList.at(index).at(other_index);
  std::cout << lastAns << std::endl;
}

int main () {

  int nn{};                     // Number of empty sequences.
  int qq{};                     // Number of queries to perform.
  unsigned long int lastAns{};  // lastAns variable.

  std::cin >> nn >> qq;

  // List of nn empty sequences.
  std::vector<std::vector<unsigned long int>> seqList(nn);

  for (int ii = 1; ii <= qq; ++ii) {
    unsigned      int type{};   // Type of query (1 or 2).
    unsigned long int xx{};     // First argument to a query.
    unsigned long int yy{};     // Second argument to a query.

    std::cin >> type >> xx >> yy;

    switch (type) {
      case 1: {
        PerformQuery1(seqList, lastAns, xx, yy);
        break;
      }
      case 2: {
        PerformQuery2(seqList, lastAns, xx, yy);
        break;
      }
      default: {
        std::cerr << "ERROR: Wrong type of query. Exiting..." << std::endl;
        return EXIT_FAILURE;
        break;
      }
    }
  }
}
