#include "solution320.h"

using std::vector;
using std::string;

vector<string> Solution320::generateAbbreviations(string s) {
    return vector<string>{};
}

vector<string> Solution320::run(string s) {
    return generateAbbreviations(s);
}

string Solution320::toStr(vector<string> vs) {
    string ret("[");
    auto it = vs.begin();
    if (it != vs.end()) {
        ret += *it;
        for (++it; it != vs.end(); ++it) {
            ret += ", " + *it;
        }
    }
    return ret += ']';
}

