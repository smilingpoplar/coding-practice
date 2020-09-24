//
//  complex-number-multiplication
//  https://leetcode.com/problems/complex-number-multiplication/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // (a+bi)*(c+di)=(ac-bd)+(ad+bc)i
        int ra, ia, rb, ib;
        char buff;
        istringstream issa(a), issb(b);
        issa >> ra >> buff >> ia >> buff;
        issb >> rb >> buff >> ib >> buff;
        ostringstream ossc;
        ossc << ra * rb - ia * ib << "+" << ra * ib + ia * rb << "i";
        return ossc.str();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
