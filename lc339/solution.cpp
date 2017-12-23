#include "solution.h"

using std::vector;

int Solution::depthSum(vector<NestedInteger>& nestedList) {
    return Solution::sum(nestedList);
}

int Solution::sum(const vector<NestedInteger>& nestedList, int level) {
    int ret = 0;
    for (auto nsi : nestedList) {
        if (nsi.isInteger())
            ret += level * nsi.getInteger();
        else
            ret += sum(nsi.getList(), level + 1);
    }
    return ret;
}
