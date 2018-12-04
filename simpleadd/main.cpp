#include <iostream>
#include <fstream>
#include <string>

#include <protocols/protocol.hpp>
#include "Add.hpp"

using namespace simple_add;
using namespace simple_add::ACSP_FOR_ADD;

using std::cout;
using std::endl;
using std::string;
using std::stoul;

using std::vector;

// a: public output, 63
// b: private input which should be one for satisfying constraints
void execute(const unsigned int a, const unsigned int b, const unsigned securityParameter) {
    AddCommonParams params;
    params.length = 1;

    libstark::BairInstance bair_instance = buildBairInstance(params);
    Add::evalp::setParams(1234);
    libstark::BairWitness bair_witness = buildBairWitness(params, a, b);

    libstark::Protocols::executeProtocol(bair_instance, bair_witness, securityParameter, false, false, true);
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        cout << "Need 2 arguments." << endl;
        return 0;
    }    

    const unsigned int a_num(stoul(argv[1]));
    const unsigned int b_num(stoul(argv[2]));
    unsigned int securityParameter = 60;
    
    execute(a_num, b_num, securityParameter);
    return 0;
}