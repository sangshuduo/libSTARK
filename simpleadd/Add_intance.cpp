#ifndef __ACSP_FOR_ADD_INSTANCE_HPP__
#define __ACSP_FOR_ADD_INSTANCE_HPP__

#include "Add.hpp"
#include "languages/Bair/ConstraintsSys.hpp"

namespace simple_add{
namespace ACSP_FOR_ADD{

    class Add_CS : public libstark::ConstraintSys{
    public:
        Add_CS();
    
    // the amount of inputs each polynomial expects
    size_t numVars() const{ return 2 * Add::NUMREGS; }
    size_t numMappings() const{ return polys_.size(); }

    Add_CS* clone() const;

    // the constraint polynomials
    const polySet_t& constraints() const{ return polys_; }
    std::vector<FieldElement> eval(const std::vector<FieldElement>& assignment) const;

    private:
        polySet_t polys_;

    };

libstark::BairInstance buildBairInstance(const AddCommonParams& params) {
    using Algebra::FieldElement;
    using Algebra::zero;
    using Algebra::mapIntegerToFieldElement;
    using libstark::BairInstance;

    const size_t vectorsLen = Add::NUMREGS;
    const short domainSizeIndicator = Add::getDim(params.length);
    BairInstance::constraintsPtr_t constraints_assignment(new Add_CS());
    BairInstance::constraintsPtr_t constraints_permutation(new empty_CS());

    BairInstance::boundaryConstraints_t boundary;
    boundary[BairInstance::point_t(0, Add::reg::B00)] = Algebra::one(); // TODO: one?
    // boundary[BairInstance::point_t(0, Add::reg::B00)] = Algebra::zero(); // TODO: Need last boundary?

    return BairInstance(vectorsLen, 
                        domainSizeIndicator, 
                        std::move(constraints_assignment), 
                        std::move(constraints_permutation), 
                        boundary,
                        std::vector<Algebra::FieldElement>(Add::NUMREGS, zero())
                        );
}

} // namespace ACSP_FOR_ADD
} // namespace simple_add



#endif // __ACSP_FOR_ADD_INSTANCE_HPP__