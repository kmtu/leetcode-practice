#include "solution734.h"
#include <unordered_set>
#include <cstddef>
#include <functional>

using std::vector;
using std::string;
using std::pair;
using std::unordered_set;
using std::size_t;

bool Solution734::areSentencesSimilar(
        vector<string>& words1, vector<string>& words2,
        vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size())
        return false;

    unordered_set<string> dict;
    for (auto p : pairs) {
        dict.insert(p.first + '/' + p.second);
    }

    for (size_t i = 0; i < words1.size(); ++i) {
        string& w1 = words1[i];
        string& w2 = words2[i];
        if (w1 != w2 && (dict.count(w1 + '/' + w2) == 0) &&
                        (dict.count(w2 + '/' + w1) == 0)) {
            return false;
        }
    }
    return true;
}

bool Solution734::run(Input734 in) {
    return areSentencesSimilar(in.words1, in.words2, in.pairs);
}

