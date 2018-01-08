#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>

template <typename inT, typename outT>
class Solution {
public:
    using input_type = inT;
    using output_type = outT;
    virtual outT run(inT) = 0;
    virtual std::string toStr(outT) = 0;
};


#endif /* SOLUTION_H */
