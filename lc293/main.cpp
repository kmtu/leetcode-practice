#include "solution.h"
#include "test.h"
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    Solution sol;
    vector<Test> tests {
        {"+++", {"--+", "+--"}},
        {"++++", {"--++", "+--+", "++--"}},
        {"+-++", {"+---"}}
    };

    bool allpass = true;
    for (auto test : tests) {
        allpass = allpass && test.run(sol);
    }

    return allpass?0:-1;
}

