#include "Add.hpp"
#include "common/Utils/ErrorHandling.hpp"

namespace simple_add{
namespace ACSP_FOR_ADD{

    using std::vector;
    using Algebra::FieldElement;
    using namespace Add;

    using namespace Algebra;

    namespace{        
        class idPermutation : public libstark::BairWitness::permutation_t{
            public:
                size_t getElementByIndex(index_t index)const {
                    return index;
                }
        };

        class coloringClass : public libstark::BairWitness::assignment_t{
            private:
                std::vector<libstark::BairWitness::color_t> coloring_;                
            public:
                coloringClass(const unsigned int t, const unsigned int b):
                    // coloring_((size_t(1) << Add::getDim(commonParams.length)) - 1, vector<FieldElement>(Add::NUMREGS)) // coloring_[127][1]                    
                    coloring_((size_t(1) << Add::getDim(t-1)) - 1 , vector<FieldElement>(Add::NUMREGS)) // coloring_[127][1]                    
                {                                                             
                    Add::genWitnessAddWithPadding(coloring_, t, b);                    
                }

                libstark::BairWitness::color_t getElementByIndex(index_t index)const{
                    _COMMON_ASSERT(index < coloring_.size(), "index of color out of range");
                    return coloring_[index];
                }
        };
    }

    libstark::BairWitness buildBairWitness(const unsigned int t, const unsigned int a){
        using libstark::BairWitness;
        BairWitness::permutation_ptr perm(new idPermutation());
        BairWitness::assignment_ptr assignment(new coloringClass(t, a));

        return BairWitness(std::move(assignment), std::move(perm));
    }
}    
}