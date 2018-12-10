#include "Add.hpp"

#define RI(n) n
#define RN 1

using namespace Algebra;

namespace Add{

    FieldElement randCoeff[RN];

    unsigned int evalp::a_param = 0;
    void evalp::setParams(const unsigned int a, const int prngseed) {
        Algebra::rng.seed(prngseed);
        evalp::a_param = a;
        for (int i = 0; i < RN; i++)
            randCoeff[i] = Algebra::generateRandom(); 
    }

    FieldElement evalp::ep(const std::vector<FieldElement>& vars) { 
        randCoeff[0] = Algebra::generateRandom();
                
        FieldElement tval = randCoeff[RI(0)] * (vars[reg::B00] + vars[reg::B01] + vars[reg::B02]);
        tval += randCoeff[RI(1)] * (vars[reg::B00 + NUMREGS] + vars[reg::B01]);
        tval += randCoeff[RI(2)] * (vars[reg::B01 + NUMREGS] + vars[reg::B02]);
        
        return tval;        
    }

} //namespace