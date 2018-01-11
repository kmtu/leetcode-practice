#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>

/* General */
template <typename inT, typename outT>
class Solution {
public:
    using input_type = inT;
    using output_type = outT;
    virtual output_type run(input_type) = 0;
    virtual std::string toStr(outT) = 0;
};

/* outT: vector<string> */
template <typename inT>
class Solution<inT, std::vector<std::string>> {
public:
    using input_type = inT;
    using output_type = std::vector<std::string>;
    virtual output_type run(input_type) = 0;
    virtual std::string toStr(output_type);
};

template <typename inT>
std::string Solution<inT, std::vector<std::string>>::toStr(output_type out) {
    std::string ret("[");
    auto it = out.begin();
    if (it != out.end()) {
        ret += *it;
        for (++it; it != out.end(); ++it) {
            ret += ", " + *it;
        }
    }
    return ret += ']';
}

/* outT: bool */
template <typename inT>
class Solution<inT, bool> {
public:
    using input_type = inT;
    using output_type = bool;
    virtual output_type run(input_type) = 0;
    virtual std::string toStr(output_type);
};

template <typename inT>
std::string Solution<inT, bool>::toStr(output_type out) {
    return out?"true":"false";
}

/* outT: vector<vector<string>> */
template <typename inT>
class Solution<inT, std::vector<std::vector<std::string>>> {
public:
    using input_type = inT;
    using output_type = std::vector<std::vector<std::string>>;
    virtual output_type run(input_type) = 0;
    virtual std::string toStr(output_type);
};

template <typename inT>
std::string Solution<inT, std::vector<std::vector<std::string>>>::toStr(
        output_type vvs) {
    std::string ret("[");
    auto vvsit = vvs.begin();
    if (vvsit != vvs.end()) {
        ret += "[";
        auto vsit = vvsit->begin();
        if (vsit != vvsit->end()) {
            ret += *vsit;
            for (++vsit; vsit != vvsit->end(); ++vsit) {
                ret += ", " + *vsit;
            }
        }
        ret += "]";
        for (++vvsit; vvsit != vvs.end(); ++vvsit) {
            ret += ",\n           [";
            auto vsit = vvsit->begin();
            if (vsit != vvsit->end()) {
                ret += *vsit;
                for (++vsit; vsit != vvsit->end(); ++vsit) {
                    ret += ", " + *vsit;
                }
            }
            ret += "]";
        }
    }
    return ret += "]";
}

#endif /* SOLUTION_H */

