// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <vector>
#include <string>

int main() {
  size_t kNumLetters{26};  // Number of letters in the alphabet.
  std::vector<int> heights(kNumLetters);  // Collection of letter heights.

  for (size_t ii = 0; ii < kNumLetters; ++ii) {
    int height{};  // Current height read.
    std::cin >> height;
    heights.at(ii) = height;
  }

  std::string word_to_highlight{};  // Word to highlight.

  std::cin.ignore();
  std::getline(std::cin, word_to_highlight);

  if (word_to_highlight.size() == 0) {
    std::cout << 0 << std::endl;
  } else {
    // Determine the letter with the greatest height.
    size_t kASCIIFora{97};  // Constant ASCII value for letter 'a'.
    int max_height{};  // Maximum height.
    for (size_t ii = 0; ii < word_to_highlight.size(); ++ii) {
      size_t letter_as_idx{static_cast<size_t>(word_to_highlight.at(ii))};
      letter_as_idx = letter_as_idx - kASCIIFora;
      if (heights.at(letter_as_idx) > max_height) {
        max_height = heights.at(letter_as_idx);
      }
    }
    // Compute area.
    int area = max_height*static_cast<int>(word_to_highlight.size());
    std::cout << area << std::endl;
  }
}
