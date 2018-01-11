#ifndef SOLUTION249_H
#define SOLUTION249_H

#include "solution.h"
#include <vector>
#include <string>

class Solution249 : public Solution<std::vector<std::string>,
                                    std::vector<std::vector<std::string>>> {
public:
    output_type run(input_type strings) override;

private:
    output_type groupStrings(input_type& string);
};

#endif /* SOLUTION249_H */
