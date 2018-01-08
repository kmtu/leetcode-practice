#ifndef SOLUTION294_H
#define SOLUTION294_H

#include "solution.h"
#include <string>
#include <vector>

class Solution294 : public Solution<std::string, bool> {
public:
    bool run(std::string) override;
    std::string toStr(bool) override;
private:
    bool canWin(std::string);
    bool secMustLose(std::string);
    std::vector<std::string> generatePossibleNextMoves(std::string);
};

#endif /* SOLUTION294_H */

