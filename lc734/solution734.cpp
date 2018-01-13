#include "solution734.h"
#include <unordered_set>
#include <cstddef>
#include <functional>

using std::vector;
using std::string;
using std::pair;
using std::unordered_set;
using std::size_t;

struct PairsHash {
    const size_t operator()(const pair<string, string>& in) const {
        size_t h1 = std::hash<string>{}(in.first);
        size_t h2 = std::hash<string>{}(in.second);
        return h1 ^ h2;
    } 
};

struct PairsEqual {
    bool operator()(
            const pair<string, string>& p1, const pair<string, string>& p2) const {
        return p1 == p2 || (p1.first == p2.second && p1.second == p2.first);
    }
};

bool Solution734::areSentencesSimilar(
        vector<string>& words1, vector<string>& words2,
        vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size())
        return false;

    unordered_set<pair<string, string>, PairsHash, PairsEqual> dict;
    for (auto p : pairs) {
        dict.insert(p);
    }

    for (size_t i = 0; i < words1.size(); ++i) {
        string& w1 = words1[i];
        string& w2 = words2[i];
        if (w1 != w2 && (dict.count(std::make_pair(w1, w2)) == 0))
            return false;
    }
    return true;
}

bool Solution734::run(Input734 in) {
    return areSentencesSimilar(in.words1, in.words2, in.pairs);
}

