//
//  palindrome-partitioning-iii
//  https://leetcode.com/problems/palindrome-partitioning-iii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    const int INF = 1e9;
public:
    int palindromePartition(string s, int k) {
        // 设dp[i][k]表示s[i..]分成k个回文的最少改动，
        // dp[i][k]=min{ cost[i..j] + dp[j+1][k-1] }，i<=j<N
        map<array<int,2>, int> memo;
        return dfs(0, k, s, memo);
    }
    
    int dfs(const int idx, const int k, const string &s, 
            map<array<int,2>, int> &memo) {
        const int N = s.size();
        if (N - idx == k) return 0; // k个单字母回文
        if (k == 1) return cost(s, idx, N - 1); // 整串变回文
        if (memo.count({idx, k})) return memo[{idx, k}];
        
        // 分成两段：[idx..j], [j+1..hi]
        int ans = INF;
        for (int j = idx; j < N; j++) {
            ans = min(ans, cost(s, idx, j) + dfs(j + 1, k - 1, s, memo));
        }
        return memo[{idx, k}] = ans;
    }
    
    int cost(const string &s, int lo, int hi) {
        int ans = 0;
        while (lo < hi) {
            if (s[lo] != s[hi]) ans++;
            lo++, hi--;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
