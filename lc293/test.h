#ifndef TEST_H
#define TEST_H

#include "solution.h"
#include <string>
#include <vector>

class Test {
    std::string str;
    std::vector<std::string> truth;
    int idx;
    static int _idx;

public:
    Test(const std::string str, const std::vector<std::string>& truth);
    bool run(Solution &sol);
};

#endif /* TEST_H */

