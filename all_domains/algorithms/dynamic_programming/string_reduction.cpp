#include <iostream>

#include <limits>

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

std::unordered_map<std::string, int> table;

int min_red_len{};

std::vector<int> FeasibleCandidates(const std::string &ss) {

  int nn{static_cast<int>(ss.length())};

  std::vector<int> candidates;

  for (int ii = 0; ii < nn - 1; ++ii) {
    if (ss[ii] != ss[ii + 1]) {
      candidates.push_back(ii);
    }
  }
  return candidates;
}

std::string PrepareStringForBacktrack(const std::string &ss, int ll) {

  std::map<std::string, char> kReplacements{
  {"ab", 'c'}, {"ac", 'b'}, {"ba", 'c'}, {"bc", 'a'}, {"ca", 'b'}, {"cb", 'a'}};

//   std::cout << ss << " will be processed for " << ll << std::endl;

  // Construct the explicit candidate from ll.
  std::string question(1, ss[ll]);
  question.push_back(ss[ll + 1]);
  // Determine the character replacing the candidate in the string.
  char cc{kReplacements[question]};

  // Prepare string for backtrack.
  std::string ss_copy(ss, 0, ll);
  ss_copy.push_back(cc);

  for (int ii = ll + 1 + 1; ii < static_cast<int>(ss.length()); ++ii) {
    ss_copy.push_back(ss[ii]);
  }

  return ss_copy;
}

int MinimumReductionLength(const std::string &ss) {

  int nn{static_cast<int>(ss.length())};    // Length of the string.

  if (nn == 1) {
    return 1;
  } else if (nn == 2 && ss[0] == ss[1]) {
    return 2;
  }

  std::vector<int> cc = FeasibleCandidates(ss);

  if (cc.empty()) {
    return nn;
  }

  for (int ll: cc) {
    std::string ss_copy = PrepareStringForBacktrack(ss, ll);
    auto prev_mrl_for_ss_copy = table.find(ss_copy);
    int aux{};
    if (prev_mrl_for_ss_copy == table.end()) {
      aux = MinimumReductionLength(ss_copy);
      table.insert(std::make_pair(ss_copy, aux));
    } else {
      aux = table[ss_copy];
    }
    if (aux == 1) {
      return 1;
    }
    if (aux < min_red_len) {
      min_red_len = aux;
    }
  }
  return min_red_len;
}

int main () {

  int tt{}; // Number of test cases.

  std::cin >> tt;
  std::cin.ignore();

  for (int ii = 1; ii <= tt; ++ii) {

    std::string ss{};

    std::getline(std::cin, ss);

    min_red_len = std::numeric_limits<int>::max();

    std::cout << MinimumReductionLength(ss) << std::endl;
  }
}
