#include "solution294.h"

using std::string;
using std::vector;

bool Solution294::canWin(string s) {
    auto moves = generatePossibleNextMoves(s);
    for (const auto& move : moves) {
        if (secMustLose(move))
            return true;
    }
    return false;
}

bool Solution294::secMustLose(string s) {
    auto moves = generatePossibleNextMoves(s);
    for (const auto& move : moves) {
        if (!canWin(move))
            return false;
    }
    return true;
}

vector<string> Solution294::generatePossibleNextMoves(string s) {
    vector<string> ret;
    size_t pos = s.find("++");
    while (pos != string::npos) {
        ret.push_back(s.substr(0, pos) + "--" + s.substr(pos + 2));
        pos = s.find("++", pos + 1);
    }
    return ret;
}

string Solution294::toStr(bool a) {
    return a?"true":"false";
}

bool Solution294::run(string s) {
    return canWin(s);
}

