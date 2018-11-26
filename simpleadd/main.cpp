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

void execute(const unsigned int a, const unsigned int b, const unsigned securityParameter) {
    AddCommonParams params;

    libstark::BairInstance bair_instance = buildBairInstance(params);
    // libstark::BairWitness bair_witness = buildBairWitness();

    // libstark::Protocols::executeProtocol(bair_instance, bair_witness, securityParameter, false, false, true);
}

int main(int argc, char *argv[]) {
    cout << "HEllo" << endl;
    return 0;
}