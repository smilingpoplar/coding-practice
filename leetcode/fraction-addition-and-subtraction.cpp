//
//  fraction-addition-and-subtraction
//  https://leetcode.com/problems/fraction-addition-and-subtraction/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        istringstream iss(expression);
        int A = 0, B = 1, a, b;
        char buff;
        while (iss >> a >> buff >> b) {
            // A/B + a/b = (A*b+a*B) / (B*b)
            A = A * b + a * B;
            B = B * b ;
            int g = gcd(abs(A), abs(B));
            A /= g;
            B /= g;            
        }
        
        ostringstream oss;
        oss << A << "/" << B;
        return oss.str();
    }
    
    int gcd(int a, int b) {
        while (b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
