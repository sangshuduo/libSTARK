#include "Add.hpp"

#define CYCLES 62 // TODO: Fix number

using namespace Algebra;


namespace Add {

    short getDim(long long len) {
        return ceil(Infrastructure::Log2((long long)CYCLES * (len + 1) - 2));
    }    

    void genWitnessAddWithPadding(witnessType arr, const unsigned int a, const unsigned int b) {
        size_t t = 0;
        arr[t][reg::B00] = one();
        for (; t < arr.size() - 1; t++) {
            arr[t + 1][reg::B00] = arr[t][reg::B00] + one();
        }
    }
}