#include "boldtag.h"
#include <map>
#include <utility>

using std::string;
using std::vector;
using std::map;
using std::make_pair;

struct Tags {
    typedef map<string::size_type, string::size_type> tag_type;
    tag_type tags;

    void squash() {
        tag_type::iterator prev = tags.begin();
        tag_type::iterator it = prev;
        ++it;
        while(it != tags.end()) {
            if (it->first <= prev->second) {
                if (it->second > prev->second)
                    prev->second = it->second;
                it = tags.erase(it);
            }
            else {
                prev = it;
                ++it;
            }
        }
    }

    auto insert(string::size_type start, string::size_type end) {
        return tags.insert(make_pair(start, end));
    }
};

class Matcher {
    const string &str;
    Tags *tags;
    string::size_type str_start;
    string::size_type str_idx;
    string::size_type acc_idx;
    bool prev_matched;

    void rewind() {
        str_idx = 0;
        prev_matched = false;
    }

public:
    Matcher(string str, Tags *tags)
        : str(str), str_idx(0), acc_idx(0), prev_matched(false) {
    }

    void match(const char& c) {
        if (str[str_idx] == c) {
            ++str_idx;
            if (prev_matched == false) {
                str_start = acc_idx;
                prev_matched = true;
            }
            if (str_idx > str.size()){
                auto dup = tags->insert(str_start, acc_idx);
                if (dup.second == false) {
                    // same index exists, replace with new acc_idx
                    // which must be larger than the old one
                    dup.first->second = acc_idx;
                }
                rewind();
            }
        }
        else rewind();
        ++acc_idx;
    }

};

string Solution::addBoldTag(string s, vector<string>& dict) {
    vector<Matcher> matchers;
    Tags tags;

    for (const auto& str : dict) {
        matchers.push_back(Matcher(str, &tags));
    }

    for (const auto& c : s) {
        for (auto& m : matchers) {
            m.match(c);
        }
    }

    tags.squash();

    string ret;
    string::size_type cur = 0;
    const string btag_open = "<b>";
    const string btag_close = "</b>";
    for (auto& tag : tags.tags) {
        int len_before_tag = tag.first - cur;
        int len_in_tag = tag.second - tag.first;
        ret.append(s, cur, len_before_tag);
        ret.append(btag_open);
        ret.append(s, tag.first, len_in_tag);
        ret.append(btag_close);
        cur = tag.second;
    }

    return ret;
}
