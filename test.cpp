#include "prod.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::pair;
using std::endl;
using std::to_string;

void test(Solution sol, pair<vector<int>, vector<int>> &testcase) {
    auto& tc = testcase.first;

    cout << "Testing [ ";
    for (int v : tc)
        cout << to_string(v) << " ";
    cout << "] ... ";

    auto& truth = testcase.second;
    auto ans = sol.productExceptSelf(tc);

    if(ans != truth) {
        cout << endl << "ans: [ ";
        for (int v : ans)
            cout << to_string(v) << " ";
        cout << "]";

        cout << endl << "truth: [ ";
        for (int v : truth)
            cout << to_string(v) << " ";
        cout << "]" << endl;

        assert(ans == truth);
    }

    cout << "Pass!" << endl;
}

int main() {
    Solution sol;
    vector<pair<vector<int>, vector<int>>> testcases = {
        {{1, 2, 3}, {6, 3, 2}},
        {{3, 4}, {4, 3}}
    };

    for (auto tc : testcases) {
        test(sol, tc);
    }
}
