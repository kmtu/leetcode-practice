#include "boldtag.h"
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;

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
    vector<pair<string::size_type, string::size_type>> tags_res;
    if (!tags.empty()) {
        tags_res.push_back(*(tags.begin()));
        for (auto it = std::next(tags.begin()); it != tags.end(); ++it) {
            if (it->first <= tags_res.back().second)
                tags_res.back().second =
                    std::max(it->second, tags_res.back().second);
            else
                tags_res.push_back(*it);
        }
    }

    // construct return string
    const string btag_open = "<b>";
    const string btag_close = "</b>";
    for (auto it = tags_res.rbegin(); it != tags_res.rend(); ++it) {
        s.insert(it->second, btag_close);
        s.insert(it->first, btag_open);
    }

    return s;
}
