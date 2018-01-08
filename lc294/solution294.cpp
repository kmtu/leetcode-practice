#include "solution294.h"

using std::string;
using std::vector;

bool Solution294::canWin(string s) {
    auto it = mem.find(s);
    if (it != mem.end())
        return it->second;
    size_t pos = s.find("++");
    while (pos != string::npos) {
        s[pos] = s[pos+1] = '-';
        bool win = !canWin(s);
        s[pos] = s[pos+1] = '+';
        if (win)
            return mem[s] = true;
        pos = s.find("++", pos + 1);
    }
    return mem[s] = false;
}

string Solution294::toStr(bool a) {
    return a?"true":"false";
}

bool Solution294::run(string s) {
    return canWin(s);
}

