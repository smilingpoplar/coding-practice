//
//  k-inverse-pairs-array
//  https://leetcode.com/problems/k-inverse-pairs-array/
//
//  Created by smilingpoplar on 17/12/07.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k > n * (n - 1) / 2) return 0;
        const int M = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 2; i <= n; i++) { // i>=2个元素才有逆序对
            for (int j = 1; j <= k; j++) {
                int val = (dp[i][j - 1] + dp[i-1][j]) % M;
                dp[i][j] = (val + M - (j >= i ? dp[i - 1][j - i] : 0)) % M;
            }
        }
        return dp[n][k];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
