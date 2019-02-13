//
//  length-of-longest-fibonacci-subsequence
//  https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        // 设dp[i][j]表示以A[i]、A[j]结尾的长>=2的最长Fib子序列长
        // 将A中值作value=>idx的映射，i,j的前一个索引idx=mp[A[j]-A[i]]，
        // dp[i][j] = dp[idx][i] + 1
        const int N = A.size();
        unordered_map<int, int> mp; // value=>idx
        vector<vector<int>> dp(N, vector<int>(N, 0));

        int ans = 0;
        for (int j = 0; j < N; j++) {
            mp[A[j]] = j;
            for (int i = 0; i < j; i++) {
                int value = A[j] - A[i];
                if (value < A[i] && mp.count(value)) {
                    int idx = mp[value];
                    dp[i][j] = dp[idx][i] + 1; // dp[i][j]现在>=3
                    ans = max(ans, dp[i][j]);                        
                } else {
                    dp[i][j] = 2;
                }                
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
