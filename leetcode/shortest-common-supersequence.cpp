//
//  shortest-common-supersequence
//  https://leetcode.com/problems/shortest-common-supersequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        // 设dp[i][j]表示a[i..]和b[j..]的LCS
        // 若a[i]==b[j]，dp[i][j]=1+dp[i+1][j+1]
        // 否则，dp[i][j]=max(dp[i][j+1], dp[i+1][j])
        // 初始，dp[i][N]=0, dp[M][j]=0
        const int M = a.size(), N = b.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }

        string ans;
        for (int i = 0, j = 0; i < M || j < N; ) {
            if (i < M && dp[i][j] == dp[i+1][j]) {
                ans += a[i++];
            } else if (j < N && dp[i][j] == dp[i][j+1]) {
                ans += b[j++];
            } else {
                ans += a[i];
                i++, j++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
