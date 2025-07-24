//
//  edit-distance
//  https://leetcode.com/problems/edit-distance/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 设dp[i][j]表示s1[i..]和s2[j..]的最小编辑距离
        // 若s1[i]==s2[j]，dp[i][j]=dp[i+1][j+1]；否则，
        // dp[i][j] = 1 + min{ dp[i+1][j]/*删除*/, dp[i][j+1]/*添加*/, dp[i+1][j+1]/*替换*/ }
        const int M = word1.size(), N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = M - 1; i >= 0; i--) dp[i][N] = M - i;
        for (int j = N - 1; j >= 0; j--) dp[M][j] = N - j;

        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                }
            }
        }
        return dp[0][0];
    }
};

int main(int argc, const char* argv[]) {
    Solution solution;
    cout << solution.minDistance("cat", "ha");

    return 0;
}
