//
//  arithmetic-slices-ii-subsequence
//  https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // 设dp[i][d]表示A[0..i]以A[i]结尾、等差为d、长度>=2的等差序列数
        // 对所有j<i，d=A[i]-A[j]，dp[i][d] += dp[j][d]+1，dp[j][d]来自变长的旧序列，1来自新出现的长度==2序列
        // 初始dp[0][]=0
        const int N = A.size();
        vector<map<int,int>> dp(N);
        int ans = 0;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                long d = (long)A[i] - A[j];
                if (d < INT_MIN || d > INT_MAX) continue; // pass OL
                dp[i][d] += dp[j][d] + 1; // dp[j][d]来自变长的旧序列，长度>=3
                ans += dp[j][d];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
