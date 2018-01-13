#ifndef SOLUTION734_H
#define SOLUTION734_H

#include "solution.h"
#include <vector>
#include <string>
#include <utility>

struct Input734 {
    std::vector<std::string> words1;
    std::vector<std::string> words2;
    std::vector<std::pair<std::string, std::string>> pairs;
};

class Solution734 : public Solution<Input734, bool> {
private:
    bool areSentencesSimilar(
            std::vector<std::string>& words1, std::vector<std::string>& words2,
            std::vector<std::pair<std::string, std::string>> pairs);
public:
    bool run(Input734) override;
};

#endif /* SOLUTION734_H */

