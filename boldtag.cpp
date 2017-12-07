#include "boldtag.h"
#include <map>

using std::string;
using std::vector;
using std::map;

class Tags {
    map<string::size_type, string::size_type> tags;

public:
    void squash() {
    }

    void insert(string::size_type start, string::size_type end) {
    }
}

class Matcher {
    string &str;
    Tags *btags;
    string::size_type match_start;
    string::size_type match_idx;
    string::size_type tot_idx;

    void rewind() {
        match_idx = 0;
    }

public:
    Matcher(string str, Tags *btags) : str(str), start(-1), idx(0) {
    }

    void match(char& c) {

    }

};

string Solution::addBoldTag(string s, vector<string>& dict) {
    vector<Matcher> matchers;
    Tags tags;

    for (auto str : dict) {
        matchers.push_back(Matcher(str, &tags));
    }

    for (auto& c : s) {
        for (auto& m : matchers) {
            m.match(c);
        }
    }

    return "";
}
