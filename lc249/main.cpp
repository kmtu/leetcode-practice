#include "solution249.h"
#include "test.h"
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

void sortVecVec(vector<vector<string>>& vvs) {
    for (auto vs : vvs) {
        std::sort(vs.begin(), vs.end());
    }
    std::sort(vvs.begin(), vvs.end(),
              [](vector<string> &a, vector<string> &b){return a[0] < b[0];});
}

int main() {
    vector<Test<Solution249>> tests {
        {{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"},
         {{"abc","bcd","xyz"}, {"az","ba"}, {"acef"}, {"a","z"}},
         sortVecVec}
    };

    bool allpass = true;
    for (auto test : tests) {
        allpass &= test.run();
    }

    return allpass?0:-1;
}

