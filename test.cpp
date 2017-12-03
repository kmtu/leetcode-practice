#include "nct.h"
#include <vector>
#include <string>
#include <utility>
#include <cassert>
#include <iostream>

using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

static void test(Solution sol, pair<string, string>& tcase) {
    string ans = sol.nextClosestTime(tcase.first);
    cout << ans << ' ' << tcase.second << endl;
    assert(ans == tcase.second);
}

int main() {
    vector<pair<string, string>> cases;
    cases.push_back(make_pair("12:34", "12:41"));
    cases.push_back(make_pair("10:08", "10:10"));
    cases.push_back(make_pair("00:01", "00:10"));
    cases.push_back(make_pair("23:58", "22:22"));
    cases.push_back(make_pair("20:56", "22:00"));

    for (auto tcase : cases) {
        Solution sol;
        test(sol, tcase);
    }
}
