#include "solution320.h"
#include "test.h"
#include <algorithm>

using std::vector;
using std::string;

void sortVec(vector<string>& vec) {
    std::sort(vec.begin(), vec.end());
}

int main() {
    vector<Test<Solution320>> tests {
        Test<Solution320>("word", {"word", "1ord", "w1rd", "wo1d",
                  "wor1", "2rd", "w2d", "wo2",
                  "1o1d", "1or1", "w1r1", "1o2",
                  "2r1", "3d", "w3", "4"}, sortVec)
    };

    bool allpass = true;
    for (auto test : tests) {
        allpass = test.run() && allpass;
    }

    return allpass?0:-1;
}
