//
//  longest-common-subsequence
//  https://leetcode.com/problems/longest-common-subsequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        // 设dp[i][j]表示a[i..]和b[j..]的LCS
        // 若a[i]==b[j]，dp[i][j]=1+dp[i+1][j+1]
        // 否则，dp[i][j]=max(dp[i][j+1], dp[i+1][j])
        // 初始，dp[i][N]=0, dp[M][j]=0
        // 第i项只依赖第i项和第i+1项，省掉i这维，使用临时变量ndp，i从右往左遍历
        const int M = a.size(), N = b.size();
        vector<int> dp(N + 1);
        for (int i = M - 1; i >= 0; i--) {
            vector<int> ndp(N + 1);
            for (int j = N - 1; j >= 0; j--) {
                if (a[i] == b[j]) ndp[j] = 1 + dp[j+1];
                else ndp[j] = max(ndp[j+1], dp[j]);
            }
            swap(dp, ndp);
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
