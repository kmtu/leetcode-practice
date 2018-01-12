#include "solution249.h"
#include <utility>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

vector<vector<string>> Solution249::groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> groups;
    for (auto str : strings) {
        string key;
        for (std::size_t i = 0; i < str.size() - 1; ++i) {
            int k = str[i+1] - str[i];
            k = (k < 0 ? k + num_alphabet : k) + 'a';
            key += k;
        }
        groups[key].push_back(std::move(str));
    }

    vector<vector<string>> ret;
    for (auto g : groups)
        ret.push_back(g.second);
    return ret;
}

vector<vector<string>> Solution249::run(input_type strings) {
    return groupStrings(strings);
}

