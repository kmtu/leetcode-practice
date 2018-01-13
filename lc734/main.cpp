#include "test.h"
#include "solution734.h"
#include <vector>

using std::vector;

int main() {
    vector<Test<Solution734>> tests;
    tests.push_back({
            {{"great","acting","skills"},
             {"fine","drama","talent"},
             {{"great","fine"},{"drama","acting"},{"skills","talent"}}},
            true});

    bool allpass = true;
    for (auto test : tests) {
        allpass &= test.run();
    }

    return allpass? 0: -1;
}

