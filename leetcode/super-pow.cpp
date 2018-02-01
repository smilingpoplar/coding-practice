//
//  super-pow
//  https://leetcode.com/problems/super-pow/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        // 37^213 mod k = 37^(210+3) mod k = ((37^21 mod k)^10 mod k) * (37^3 mod k)
        if (b.empty()) return 1;
        const int k = 1337;
        int lastDigit = b.back();
        b.pop_back();        
        return (pow(superPow(a, b), 10, k) * pow(a, lastDigit, k)) % k;
    }
    
    int pow(long a, int b, int k) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = (ans * a) % k;
            a = (a * a) % k;
            b >>= 1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
