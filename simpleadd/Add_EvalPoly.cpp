#include "Add.hpp"

#define RI(n) n
#define RN 1

using namespace Algebra;

namespace Add{

    FieldElement randCoeff[RN];

    void evalp::setParams(const int prngseed) {
        Algebra::rng.seed(prngseed);
        for (int i = 0; i < RN; i++)
            randCoeff[i] = Algebra::generateRandom(); 
    }

    FieldElement evalp::ep(const std::vector<FieldElement>& vars) { // TODO
        randCoeff[0] = Algebra::generateRandom();
        return randCoeff[RI(0)] * (vars[reg::B00 + NUMREGS] + vars[reg::B00]);
    }

} //namespace