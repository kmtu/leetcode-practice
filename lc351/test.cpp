#include "solution.h"
#include <vector>
#include <iostream>

class Test {
    int n;
    int m;
    int truth;
    int idx;
    static int _idx;

public:
    Test(int n, int m, int truth) : n(n), m(m), truth(truth) {
        idx = _idx++;
    }

    void run(Solution& sol) {
        std::cout << "Test " << idx << " ... ";
        int ans = sol.numberOfPatterns(n, m);
        if (ans != truth) {
            std::cout << "failed!" << std::endl;
            std::cout << "  n, m = " << n << ", " << m << std::endl;
            std::cout << "  ans = " << ans << std::endl;
            std::cout << "  truth = " << truth << std::endl;
        }
        else {
            std::cout << "passed!" << std::endl;
        }
    }
};

int Test::_idx = 0;

int main() {
    Solution sol;
    std::vector<Test> tests {{1, 1, 1},
                             {2, 2, 40}};

    for (auto test : tests) {
        test.run(sol);
    }
}
