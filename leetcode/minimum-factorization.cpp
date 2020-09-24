//
//  minimum-factorization
//  https://leetcode.com/problems/minimum-factorization/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10) return a;
        // a要分解成单数字因子，且个数越少越好，所以从9到2地尝试分解
        long ans = 0, base = 1;
        for (int i = 9; i >= 2; i--) {
            while (a % i == 0) {
                ans += i * base;
                if (ans > INT_MAX) return 0;
                a /= i;
                base *= 10;
            }
        }
        return (a == 1) ? ans : 0;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
