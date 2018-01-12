#ifndef SOLUTION249_H
#define SOLUTION249_H

#include "solution.h"
#include <vector>
#include <string>
#include <functional>
#include <cstddef>

class Solution249 : public Solution<std::vector<std::string>,
                                    std::vector<std::vector<std::string>>> {
public:
    output_type run(input_type strings) override;

private:
    static const int num_alphabet = 26;
    output_type groupStrings(input_type& strings);
};

#endif /* SOLUTION249_H */
