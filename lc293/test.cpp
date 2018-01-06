#include "test.h"
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int Test::_idx = 0;

Test::Test(const string str, const vector<string>& truth)
        : str(str), truth(truth), idx(_idx++) {
}

bool Test::run(Solution &sol) {
    bool passed = false;
    cout << "Test" << idx << " ... ";
    const auto ans = sol.generatePossibleNextMoves(str);
    if (ans == truth) {
        cout << "passed!" << endl;
        passed = true;
    }
    else {
        cout << "failed!" << endl;
        cout << "  ans   = [\"";
        if (!ans.empty()) {
            std::copy(ans.begin(), ans.end()-1,
                    std::ostream_iterator<decltype(ans)::value_type>(cout, "\", \""));
            cout << ans.back();
        }
        cout << "\"]" << endl;
        cout << "  truth = [\"";
        if (!truth.empty()) {
            std::copy(truth.begin(), truth.end()-1,
                    std::ostream_iterator<decltype(truth)::value_type>(cout, "\", \""));
            cout << truth.back();
        }
        cout << "\"]" << endl;
    }
    return passed;
}

