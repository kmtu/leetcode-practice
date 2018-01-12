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
    using Key = std::vector<std::size_t>;
    struct HashKey {
        std::size_t operator()(const Key& key) const {
            std::size_t ret = std::hash<size_t>()(key.size());
            for (auto k : key) {
                ret ^= std::hash<std::size_t>()(k);
            }
            return ret;
        }
    };
};

#endif /* SOLUTION249_H */
