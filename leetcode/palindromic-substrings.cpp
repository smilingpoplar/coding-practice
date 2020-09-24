//
//  palindromic-substrings
//  https://leetcode.com/problems/palindromic-substrings/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // 设dp[i][j]表示s[i..j]是否是回文串，0<=i<=j<N
        // dp[i][j] = s[i]==s[j] && dp[i+1][j-1]
        // dp在i维上只依赖i+1项，可省掉i维，i仍从右往左遍历
        // 要让dp[j-1]表示旧状态dp[i+1][j-1]，j从右往左遍历
        const int N = s.size();
        vector<bool> dp(N, false);
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= i; j--) {
                dp[j] = (s[i] == s[j]);
                if (i + 1 <= j - 1) dp[j] = dp[j] && dp[j-1];

                if (dp[j]) ans++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
