//
//  prime-number-of-set-bits-in-binary-representation
//  https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        // L,R <= 2^20，二进制中最多有20位1s
        int ans = 0;
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
        for (int i = L; i <= R; i++) {
            if (primes.count(count1s(i))) ans++;
        }
        return ans;
    }
    
    int count1s(int n) {
        int count = 0;
        while (n) {
            n &= n-1;
            count++;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
