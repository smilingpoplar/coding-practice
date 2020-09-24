//
//  longest-arithmetic-subsequence-of-given-difference
//  https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // 最长指定差的子序列长
        // ~~O(n^2)解法超时：设dp[i]表示以A[i]结尾、等差为difference的子问题解~~
        // 设dp[v]表示子序列结尾值为v的子问题解，dp[v] = dp[v-difference]+1
        unordered_map<int, int> dp; // 子序列结尾值v=>子序列长
        int ans = 0;
        for (int v : arr) {
            int nv = dp.count(v - difference) ? dp[v - difference] + 1 : 1;
            dp[v] = max(dp[v], nv);
            ans = max(ans, dp[v]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
