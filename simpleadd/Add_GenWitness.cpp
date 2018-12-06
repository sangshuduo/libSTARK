#include "Add.hpp"

#define CYCLES 3 // TODO: Fix number

using namespace Algebra;


namespace Add {      

    #define DBGGET(a,b,c) (a)[(b)][(c)]

    void SaveRegisters(witnessType arr, size_t t) {
        for (int i = 0; i < NUMREGS; i++) {
            DBGGET(arr, t + 1, i) = arr[t][i];
        }
    }

    void genWitnessAddWithPadding(witnessType arr, const unsigned int a, const unsigned int b) {
        size_t t = 0;
        // size_t s = 0;
        const FieldElement oneTransformed = mapIntegerToFieldElement(0, 64, 1);
        // const size_t oneTransforming = mapFieldElementToInteger(0, 0, oneTransformed);
        DBGGET(arr, t, reg::B00) = oneTransformed;
        // DBGGET(arr, 1, reg::B00) = mapIntegerToFieldElement(0, 64, a+1);
        // DBGGET(arr, 2, reg::B00) = mapIntegerToFieldElement(0, 64, b);
        for (; t < arr.size() - 1; ++t) {
            DBGGET(arr, t + 1, reg::B00) = arr[t][reg::B00] + oneTransformed;
        }
        // DBGGET(arr, 3, reg::B00) = mapIntegerToFieldElement(0, 64, 3);

        // cout << "oneTransformedpyth" << arr[0][0] << endl;
        // // cout << "oneTransformedpyth" << oneTransforming << endl;
        // cout << "before" << arr[0][0] << endl;
        // for (; t < arr.size() - 1; t++) {
        //     // SaveRegisters(arr, t);
        //     // if (arr[t][0] == zero()){
        //         DBGGET(arr, t + 1, reg::B00) = arr[t][reg::B00] + one();
        //     // } else {
        //     //     for (; arr[t][reg::B00].element_.c[s]; ++s) {

        //     //     }
        //     //     FieldElement sTransformed = mapIntegerToFieldElement(s, 0, 1);
        //     //     FieldElement uTransformed = mapIntegerToFieldElement(s - 1, 0, 1);
        //     //     DBGGET(arr, t + 1, reg::B00) = arr[t][reg::B00] + sTransformed;
        //     //     DBGGET(arr, t + 1, reg::B00) = arr[t][reg::B00] + uTransformed;
        //     //     s++;
        //     // }            
        // }
        cout<< "after" << arr[0][0]<<endl;
        cout << "after" << arr[1][0] << endl;
        // cout << "after" << arr[2][0] << endl;
        // cout << "after" << arr[3][0] << endl;
    }

    short getDim(long long len)
    {
        return ceil(Infrastructure::Log2((long long)CYCLES * (len + 1) - 2));
    }
}