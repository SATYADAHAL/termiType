#ifndef WORD_GENERATOR_H
#define WORD_GENERATOR_H

#include "embedded_words.h"
#include <vector>
#include <string>
#include <sstream>
#include <random>

class WordGenerator {
private:
  std::vector<std::string> words;
  std::mt19937 gen;

public:
  WordGenerator() {
    std::istringstream stream(wordlist_raw);
    std::string word;
    while (std::getline(stream, word)) {
      if (!word.empty()) {
        words.push_back(word);
      }
    }

    std::random_device rd;
    gen = std::mt19937(rd());
  }

  std::string get_text(int word_count) {
    if (words.empty()) return "";

    std::uniform_int_distribution<> dis(0, words.size() - 1);
    std::string result;

    for (int i = 0; i < word_count; ++i) {
      result += words[dis(gen)];
      if (i < word_count - 1) result += " ";
    }
    return result;
  }
};

#endif // WORD_GENERATOR_H
