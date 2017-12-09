#include "boldtag.h"
#include <cassert>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Test {
    string str;
    vector<string> dict;
    string truth;
    static int idx;

public:
    Test(string str, vector<string> dict, string truth)
        : str(str), dict(dict), truth(truth) {
    }

    void run(Solution sol) {
        cout << "Test " << ++idx << " ...";
        string ans = sol.addBoldTag(str, dict);
        if (ans != truth) {
            cout << endl << "  Input: " << str << endl;
            cout << "         [ ";
            for (auto s : dict) {
                cout << s << ' ';
            }
            cout << ']' << endl;
            cout << "  Truth: " << truth << endl;
            cout << "  Ans: " << ans << endl;
            assert(ans == truth);
        }
        cout << " passed" << endl;
    }
};

int Test::idx = 0;

int main() {
    Solution sol;
    vector<Test> tests;
    tests.push_back(Test("abc", {"a", "c"}, "<b>a</b>b<b>c</b>"));
    tests.push_back(Test("abc", {"b", "c"}, "a<b>bc</b>"));
    tests.push_back(Test("abc", {"ab", "bc"}, "<b>abc</b>"));

    for (auto test : tests) {
        test.run(sol);
    }
}
