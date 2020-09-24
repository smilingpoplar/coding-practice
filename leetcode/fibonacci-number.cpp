//
//  fibonacci-number
//  https://leetcode.com/problems/fibonacci-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int prev1 = 1, prev2 = 0;
        for (int i = 2; i <= N; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
