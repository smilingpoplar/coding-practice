//
//  super-pow
//  https://leetcode.com/problems/super-pow/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        // 幂太大，将幂分解。
        // 例如，37^213 mod K = 37^(210+3) mod K 
        //   = ((37^21 mod K)^10 mod K) * (37^3 mod K)
        if (b.empty()) return 1;
        const int K = 1337;
        int lastDigit = b.back(); b.pop_back();        
        return (pow(superPow(a, b), 10, K) * pow(a, lastDigit, K)) % K;
    }
    
    // 幂较小用该函数计算，a^k mod K
    int pow(long a, int b, int K) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = (ans * a) % K;
            a = (a * a) % K;
            b >>= 1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
