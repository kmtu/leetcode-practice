#include "solution.h"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

int Solution::numberOfPatterns(int m, int n) {
    return Solution::dfs(1, m, n) * 4 + Solution::dfs(2, m, n) * 4 + Solution::dfs(5, m, n);
}

int Solution::dfs(int start, int m, int n) {
    stack<int> search;
    search.push(start);
    vector<bool> pressed(10, false);
    int patternCount = 0;
    int numKeyPressed = 0;
    while (!search.empty()) {
        int key = search.top();
        if (pressed[key]) {
            search.pop();
            pressed[key] = false;
            --numKeyPressed;
            continue;
        }
        pressed[key] = true;
        ++numKeyPressed;
        if (numKeyPressed >= m && numKeyPressed <= n) {
            ++patternCount;
            if (numKeyPressed == n)
                continue;
        }

        bool k2 = (key % 2 == 0);
        for (vector<bool>::size_type nextKey = 1; nextKey < pressed.size(); ++nextKey) {
            if (pressed[nextKey])
                continue;

            bool nk2 = (nextKey % 2 == 0);
            if (k2 && nk2) {
                if (key + nextKey == 10 && !pressed[5])
                    continue;
            }
            else if (!k2 && !nk2) {
                if (key !=5 && nextKey != 5 && !pressed[(key + nextKey) / 2])
                    continue;
            }
            search.push(nextKey);
        }
    }
    return patternCount;
}
