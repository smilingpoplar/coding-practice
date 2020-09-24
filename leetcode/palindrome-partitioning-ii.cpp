//
//  palindrome-partitioning-ii
//  https://leetcode.com/problems/palindrome-partitioning-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        // 设dp[i][j]表示s[i..j]是回文串，0<=i<=j<N
        // dp[i][j] = s[i]==s[j] && dp[i+1][j-1]
        const int N = s.size();
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i; j < N; j++) {
                dp[i][j] = s[i] == s[j];
                if (i + 1 <= j - 1) dp[i][j] = dp[i][j] && dp[i+1][j-1];
            }
        }

        // 设cut[i]表示子串s[0..i]的minCut，0<=i<N
        // dp[0][i]==true时，cut[i]=0；否则，
        // 对于0<=k<i的k若满足dp[k+1][i]==true，cut[i]=min{ cut[k]+1 }
        vector<int> cut(N, INT_MAX);
        for (int i = 0; i < N; i++) {
            if (dp[0][i]) {
                cut[i] = 0;
            } else {
                for (int k = 0; k < i; k++) {
                    if (dp[k+1][i]) {
                        cut[i] = min(cut[i], cut[k] + 1);
                    }
                }
            }
        }
        return cut[N-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.minCut("aab");
    
    return 0;
}
