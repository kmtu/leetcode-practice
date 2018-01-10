#include "solution320.h"

using std::vector;
using std::string;

vector<string> Solution320::generateAbbreviations(string word) {
    vector<string> ret{};
    gen("", 0, word, 0, ret);
    return ret;
}

void Solution320::gen(
        const string abbr, int cnt, const string& word, string::size_type idx,
        vector<string>& ret) {
    // According to test runs, it is faster to not modify abbr,
    // so just make it a const
    if (idx == word.size()) {
        if (cnt > 0)
            ret.push_back(abbr + std::to_string(cnt));
        else
            ret.push_back(abbr);
    }
    else {
        gen(abbr, cnt + 1, word, idx + 1, ret);
        if (cnt > 0)
            gen(abbr + std::to_string(cnt) + word[idx], 0, word, idx + 1, ret);
        else
            gen(abbr + word[idx], 0, word, idx + 1, ret);
    }
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

