#include "Add.hpp"

#define CYCLES 62 // TODO: Fix number

using namespace Algebra;

namespace Add {

    short getDim(long long len) {
        return ceil(Infrastructure::Log2((long long)CYCLES * (len + 1) - 2));
    }
}