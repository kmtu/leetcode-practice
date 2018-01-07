#ifndef TEST_H
#define TEST_H

#include "solution.h"
#include <iostream>

template <typename solT>
class Test {
    using inT = typename solT::input_type;
    using outT = typename solT::output_type;
    static int nextIndex;
    int index;
    bool passed;
    inT input;
    outT truth;

public:
    Test(inT input, outT truth)
        : index(nextIndex++), passed(false), input(input), truth(truth) {
    }

    bool run() {
        solT sol;
        outT ans = sol.run(input);

        std::cout << "Test" << index << " ... ";
        if (ans == truth) {
            std::cout << "passed!" << std::endl;
            return true;
        }
        else {
            std::cout << "failed!" << std::endl;
            std::cout << "  truth = " << sol.toStr(truth) << std::endl;
            std::cout << "  ans   = " << sol.toStr(ans) << std::endl;
            return false;
        }
    }
};

template <typename T>
int Test<T>::nextIndex = 0;

#endif /* TEST_H */

