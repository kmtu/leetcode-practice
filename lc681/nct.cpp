#include "nct.h"
#include <vector>
#include <set>
#include <iostream>

using std::vector;
using std::set;

string Solution::nextClosestTime(string time) {
    set<char> digits;
    vector<set<char>::iterator> ntime;
    for (char& c : time) {
        if (c != ':')
            ntime.push_back(digits.insert(c).first);
    }

    for (int i = 3; i >=0; --i) {
        auto& nt = ++(ntime[i]);
        if ((nt == digits.end()) ||
            (i == 2 && *nt > '5') ||
            (i == 1 && *(ntime[0]) == '2' && *nt > '3') ||
            (i == 0 && *nt > '2'))
            nt = digits.begin();
        else
            break;
    }

    string ret;
    for (int i = 0; i < 4; ++i) {
        ret += *(ntime[i]);
        if (i == 1)
            ret += ':';
    }

    return ret;
}
