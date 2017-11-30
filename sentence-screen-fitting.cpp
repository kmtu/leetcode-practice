#include "sentence-screen-fitting.h"

int Solution::wordsTyping(std::vector<std::string>& sentence, int rows, int cols) {
    int i = 0, ret = 0;
    int r = 1;
    for (; r <= rows; ++r) {
        int j = i;
        int c = sentence[i].size();
        while (c <= cols) {
            if (j == sentence.size() - 1)
                ret++;
            j = (j + 1) % sentence.size();
            c += sentence[j].size() + 1;
        }
        i = j;
        if (i == 0)  // line pattern found
            break;
    }
    return (rows / r) * ret;
}
