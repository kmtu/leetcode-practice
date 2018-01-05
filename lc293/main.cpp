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

    for (auto test : tests) {
        test.run(sol);
    }
}
