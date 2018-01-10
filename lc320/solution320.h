#include "solution.h"
#include <vector>
#include <string>

class Solution320 : public Solution<std::string, std::vector<std::string>> {
public:
    std::vector<std::string> run(std::string) override;
    std::string toStr(std::vector<std::string>) override;
private:
    std::vector<std::string> generateAbbreviations(std::string word);
    void gen(std::string abbr, int cnt, const std::string& word,
             std::string::size_type idx, std::vector<std::string>& ret);
};
