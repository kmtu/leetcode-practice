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
        if (prev != tags.end())
            ++it;
        else
            return;

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
};

class Matcher {
    const string str;
    Tags *tags;
    string::size_type str_start;
    string::size_type str_idx;
    string::size_type acc_idx;
    bool prev_matched;
    bool all_same_so_far;

    void rewind() {
        str_idx = 0;
        prev_matched = false;
        all_same_so_far = true;
    }

public:
    Matcher(string str, Tags *tags) : str(str), tags(tags), acc_idx(0) {
        rewind();
    }

    void match(const char& c) {
        if (str[str_idx] == c) {
            if (prev_matched) {
                if (all_same_so_far && (c != str[str_idx-1])) {
                    all_same_so_far = false;
                }
            }
            else {
                str_start = acc_idx;
                prev_matched = true;
            }
            ++str_idx;
            if (str_idx == str.size()){
                auto dup = tags->tags.insert(make_pair(str_start, acc_idx + 1));
                if (dup.second == false) {
                    // same index exists, replace with new acc_idx
                    // which must be larger than the old one
                    dup.first->second = acc_idx + 1;
                }
                rewind();
            }
        }
        else {
            if (prev_matched && all_same_so_far && (c == str[str_idx-1])) {
                ++str_start;
            }
            else {
                rewind();
            }
        }
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

    // resolve overlapped/consecutive tags
    tags.squash();

    // construct return string
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
    ret.append(s.begin() + cur, s.end());

    return ret;
}
