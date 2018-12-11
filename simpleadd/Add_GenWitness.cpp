#include "Add.hpp"

#define CYCLES 62 // TODO: Fix number

using namespace Algebra;


namespace Add {      

    #define DBGGET(a,b,c) (a)[(b)][(c)]

    // void SaveRegisters(witnessType arr, size_t t) {
    //     for (int i = 0; i < NUMREGS; i++) {
    //         DBGGET(arr, t + 1, i) = arr[t][i];
    //     }
    // }

    void genWitnessAddWithPadding(witnessType arr, const unsigned int t, const unsigned int a) {                               
        DBGGET(arr, 0, reg::B00) = zero();
        DBGGET(arr, 0, reg::B01) = zero();
        DBGGET(arr, 0, reg::B02) = one();
        
        DBGGET(arr, 1, reg::B00) = zero();
        DBGGET(arr, 1, reg::B01) = one();

        for (size_t i = 1;i < t - 1; i++) {            
            size_t b0_num = mapFieldElementToInteger(0, 64, arr[i][reg::B00]);
            size_t b1_num = mapFieldElementToInteger(0, 64, arr[i][reg::B01]);            

            DBGGET(arr, i, reg::B02) = mapIntegerToFieldElement(0, 64, b0_num + b1_num);

            DBGGET(arr, i + 1, reg::B00) = arr[i][reg::B01];
            DBGGET(arr, i + 1, reg::B01) = arr[i][reg::B02];
           
        }

        DBGGET(arr, t-1, reg::B02) = mapIntegerToFieldElement(0, 64, a);        

        // cout << "after" << mapFieldElementToInteger(0, 64, arr[7][reg::B00]) << endl;
    }

    short getDim(long long len)
    {
        // return ceil(Infrastructure::Log2((long long)CYCLES * (len + 1) - 2));
        return ceil(Infrastructure::Log2(59LL * len));
    }
} // namespace