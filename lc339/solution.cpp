#include "solution.h"

using std::vector;

int Solution::depthSum(vector<NestedInteger>& nestedList) {
    int ret = 0;
	for (auto nsi : nestedList) {
        ret += sum(nsi);
    }
    return ret;
}

int Solution::sum(NestedInteger& nestedInt, int level = 1) {
    if (nestedInt.isInteger())
        return level * nestedInt.getInteger();

    int ret = 0;
    for (auto nsi : nestedInt.getList()) {
        ret += sum(nsi, level + 1);
    }
    return ret;
}
