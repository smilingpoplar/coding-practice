//
//  climbing-stairs
//  https://leetcode.com/problems/climbing-stairs/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // dp[n]=dp[n-1]+dp[n-2]，初始dp[0]=dp[1]=1
        int prev1 = 1, prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.climbStairs(2);
    
    return 0;
}
