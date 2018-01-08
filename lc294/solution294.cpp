#include "solution294.h"

using std::string;
using std::vector;

bool Solution294::canWin(string s) {
    size_t pos = s.find("++");
    while (pos != string::npos) {
        if (!canWin(s.substr(0, pos) + "--" + s.substr(pos + 2)))
            return true;
        pos = s.find("++", pos + 1);
    }
    return false;
}

string Solution294::toStr(bool a) {
    return a?"true":"false";
}

bool Solution294::run(string s) {
    return canWin(s);
}

