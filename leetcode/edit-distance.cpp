//
//  edit-distance
//  https://leetcode.com/problems/edit-distance/
//
//  Created by smilingpoplar on 15/8/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 设dp[i,j]表示s1[0,i)和s2[0,j)的最小编辑距离
        // 当s1[i-1]==s2[j-1]，dp[i,j]=dp[i-1,j-1]；否则，
        // dp[i,j] = 1 + min{ dp[i-1,j]/*添加*/, dp[i,j-1]/*删除*/,dp[i-1,j-1]/*替换*/ }
        const int M = word1.size(), N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; i++) dp[i][0] = i;
        for (int j = 1; j <= N; j++) dp[0][j] = j;
        
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[M][N];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.minDistance("cat", "ha");
    
    return 0;
}
