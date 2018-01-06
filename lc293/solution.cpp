#include "solution.h"
#include <cstddef>

using std::vector;
using std::string;

vector<string> Solution::generatePossibleNextMoves(string s) {
    vector<string> ret;
    size_t pos = s.find("++");
    while (pos != string::npos) {
        string move;
        if (pos > 0)
            move += s.substr(0, pos);
        move += "--";
        if (pos < s.size() - 2)
            move += s.substr(pos + 2, s.size() - 1);
        ret.push_back(move);
        pos = s.find("++", pos + 1);
    }
    return ret;
}

