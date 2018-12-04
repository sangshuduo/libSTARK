#ifndef __ACSP_FOR_ADD_HPP__
#define __ACSP_FOR_ADD_HPP__

#include "languages/Bair/BairInstance.hpp"
#include "languages/Bair/BairWitness.hpp"

#include <algebraLib/BitExtract.hpp>

#define EXTDIM 64 // TODO: fix number

using namespace Algebra;

namespace Add {

    class evalp {
        public:
            static void setParams(const int);
            static FieldElement ep(const std::vector<FieldElement>&);
        private:
            static std::vector<FieldElement> rHash;
            static FieldElement last_leaf_index;
    };

    const short NUMREGS = 1;     

    namespace reg
    {
    typedef enum RegType
    {
        B00 = 0    
    } RegType;
    }

    typedef std::vector<std::vector<FieldElement>> & witnessType;
    short getDim(long long);
    void genWitnessAddWithPadding(witnessType arr, const unsigned int a, const unsigned int b);
}


namespace simple_add{
    namespace ACSP_FOR_ADD{
        typedef struct{
            long long length;
            std::vector<Algebra::FieldElement> head;
        }AddCommonParams;

        libstark::BairInstance buildBairInstance(const AddCommonParams&);
        libstark::BairWitness buildBairWitness(const AddCommonParams&, const unsigned int, const unsigned int);
    }
}

#endif // __ACSP_FOR_ADD_HPP__