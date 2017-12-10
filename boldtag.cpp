#include "boldtag.h"
#include <map>
#include <utility>
#include <iterator>

using std::string;
using std::vector;
using std::map;
using std::make_pair;

string Solution::addBoldTag(string s, vector<string>& dict) {
    typedef map<string::size_type, string::size_type> tag_type;
    tag_type tags;

    // construct tags map
    for (string::size_type i = 0; i < s.size(); ++i) {
        for (const string& str : dict) {
            int comp = s.compare(i, str.size(), str);
            if (comp == 0) {
				auto iend = i + str.size();
                auto dup = tags.insert(make_pair(i, iend));
                if (dup.second == false) {
                    // same index exists, replace with new iend
                    // which must be larger than the old one
                    dup.first->second = iend;
                }
            }
        }
    }

    // resolve overlapped/consecutive tags
    tag_type::iterator prev = tags.begin();
    if (prev != tags.end()) {
        tag_type::iterator it = std::next(prev);
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

    // construct return string
    string ret;
    string::size_type cur = 0;
    const string btag_open = "<b>";
    const string btag_close = "</b>";
    for (auto& tag : tags) {
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
