#include "prod.h"

vector<int> Solution::productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> ret(size);

    ret[0] = 1;
    for (int i = 1; i < size; ++i) {
        ret[i] = ret[i - 1] * nums[i - 1];
    }

    int x = 1;
    for (int i = size - 2; i >=0; --i) {
        x *= nums[i + 1];
        ret[i] *= x;
    }
    return ret;
}
