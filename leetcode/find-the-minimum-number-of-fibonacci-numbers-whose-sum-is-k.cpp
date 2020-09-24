//
//  find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
//  https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 0) return 0;
        // 找<=k的最大fib数
        int a = 1, b = 1;
        while (b <= k) {
            int tmpA = a;
            a = b;
            b = tmpA + b;
        }
        return 1 + findMinFibonacciNumbers(k - a);
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
