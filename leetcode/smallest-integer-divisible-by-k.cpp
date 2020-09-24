//
//  smallest-integer-divisible-by-k
//  https://leetcode.com/problems/smallest-integer-divisible-by-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // K个连续'1'一定能整除K
        set<int> seen; // 见过的余数
        int num = 0;
        for (int i = 1; i <= K; i++) {
            num = (num * 10 + 1) % K;
            if (num == 0) return i;
            if (seen.count(num)) return -1;
            seen.insert(num);
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
