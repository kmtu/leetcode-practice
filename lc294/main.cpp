#include "solution294.h"
#include "test.h"
#include <vector>

using std::vector;

int main() {
    vector<Test<Solution294>> tests {
        {"++++", true},
        {"+++++", false}
    };

    bool allpass = true;
    for (auto test : tests)
        allpass = test.run() && allpass;

    return allpass?0:-1;
}
