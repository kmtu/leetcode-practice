#include "sentence-screen-fitting.h"

int Solution::wordsTyping(std::vector<std::string>& sentence, int rows, int cols) {
    int i = 0, rep = 0;
    int r = 0;
    std::vector<int> reps;

    for (; r < rows; ++r) {
        int j = i;
        int c = sentence[i].size();
        while (c <= cols) {
            if (j == sentence.size() - 1)
                rep++;
            j = (j + 1) % sentence.size();
            c += sentence[j].size() + 1;
        }
        reps.push_back(rep);
        i = j;
        if (i == 0) {  // line pattern found
            ++r;
            break;
        }
    }

    return (rows / r) * rep + reps[(rows % r) - 1];
}

