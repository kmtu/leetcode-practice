#ifndef SOLUTION294_H
#define SOLUTION294_H

#include "solution.h"
#include <string>
#include <vector>
#include <unordered_map>

class Solution294 : public Solution<std::string, bool> {
public:
    bool run(std::string) override;
    std::string toStr(bool) override;
private:
    bool canWin(std::string);
    std::unordered_map<std::string, bool> mem;
};

#endif /* SOLUTION294_H */

