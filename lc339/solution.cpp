#include "solution.h"

using std::vector;

int Solution::depthSum(vector<NestedInteger>& nestedList) {
    int res = 0;
    Solution::sum(nestedList, 1, res);
    return res;
}

void Solution::sum(const vector<NestedInteger>& nestedList, int level, int& result) {
    for (auto nsi : nestedList) {
        if (nsi.isInteger())
            result += level * nsi.getInteger();
        else
            sum(nsi.getList(), level + 1, result);
    }
}
