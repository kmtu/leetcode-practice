#include <iostream>
#include <string>
#include <vector>
#include "sentence-screen-fitting.h"

int main() {
    Solution sol;
    std::vector<std::string> sentence;
    int rows, cols;

    rows = 3;
    cols = 5;
    sentence = {"hello", "world"};
    std::cout << sol.wordsTyping(sentence, rows, cols) << std::endl;

    rows = 3;
    cols = 5;
    sentence = {"he", "o", "a"};
    std::cout << sol.wordsTyping(sentence, rows, cols) << std::endl;

    rows = 100;
    cols = 100;
    sentence = {"a"};
    std::cout << sol.wordsTyping(sentence, rows, cols) << std::endl;

    rows = 4;
    cols = 5;
    sentence = {"I", "had", "apple", "pie"};
    std::cout << sol.wordsTyping(sentence, rows, cols) << std::endl;
}
