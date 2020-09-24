//
//  longest-arithmetic-sequence
//  https://leetcode.com/problems/longest-arithmetic-sequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        // 最长等差子序列长
        // 设dp[i][d]表示以A[i]结尾、等差为d的子问题解
        const int N = A.size();
        vector<unordered_map<int,int>> dp(N);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                int d = A[i] - A[j];
                dp[i][d] = dp[j].count(d) ? (dp[j][d] + 1) : 2;
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
