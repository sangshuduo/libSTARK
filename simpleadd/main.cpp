#include <iostream>
#include <fstream>
#include <string>
#include <languages/Bair/BairWitnessChecker.hpp>

#include <protocols/protocol.hpp>
#include "Add.hpp"

using namespace simple_add;
using namespace simple_add::ACSP_FOR_ADD;

using std::cout;
using std::endl;
using std::string;
using std::stoul;

using std::vector;

// t: public input of the fibonacci sequence iterations
// a: private input of the `t`th number of the fibonacci sequence
void execute(const unsigned t, const unsigned int a, const unsigned securityParameter) {
    
    libstark::BairInstance bair_instance = buildBairInstance(t, a);
    Add::evalp::setParams(a, 1234);
    libstark::BairWitness bair_witness = buildBairWitness(t, a);

    std::cout << "verify:" << libstark::BairWitnessChecker::verify(bair_instance, bair_witness) << std::endl;   
    libstark::Protocols::executeProtocol(bair_instance, bair_witness, securityParameter, false, false, true);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "please put 2 arguments." << endl;
        return 0;
    }

    const unsigned int t_num(stoul(argv[1]));
    const unsigned int a_num(stoul(argv[2]));
    unsigned int securityParameter = 60;

    execute(t_num, a_num, securityParameter);
    return 0;
}