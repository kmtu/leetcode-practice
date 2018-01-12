#include "solution249.h"
#include <utility>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

vector<vector<string>> Solution249::groupStrings(vector<string>& strings) {
    vector<Key> keys;
    for (auto str : strings) {
        Key key;
        // assert(str.size() >= 1)
        for (std::size_t i = 0; i < str.size() - 1; ++i) {
            int k = str[i+1] - str[i];
            k = k < 0 ? k + num_alphabet : k;
            key.emplace_back(static_cast<std::size_t>(k));
        }
        keys.push_back(std::move(key));
    }

    unordered_map<Key, vector<string>, HashKey> groups;
    for (std::size_t i = 0; i < strings.size(); ++i) {
        Key key = keys[i];
        groups[key].push_back(strings[i]);
    }
    
    vector<vector<string>> ret;
    for (auto g : groups)
        ret.push_back(g.second);
    return ret;
}

vector<vector<string>> Solution249::run(input_type strings) {
    return groupStrings(strings);
}

