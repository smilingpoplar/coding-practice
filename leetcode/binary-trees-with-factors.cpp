//
//  binary-trees-with-factors
//  https://leetcode.com/problems/binary-trees-with-factors/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        const int N = A.size(), MOD = 1e9 + 7;
        sort(A.begin(), A.end());
        unordered_map<int, int> mp; // val=>idx
        for (int i = 0; i < N; i++)
            mp[A[i]] = i;

        // 设dp[i]表示以A[i]为根的子树有多少个
        vector<long> dp(N, 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0) {
                    int val = A[i] / A[j];
                    if (mp.count(val)) { // 以A[j]、A[mp[val]]为左右子树
                        dp[i] = (dp[i] + dp[j] * dp[mp[val]]) % MOD;
                    }
                }
            }
        }
        
        long ans = 0;
        for (long x : dp) ans += x;
        return ans % MOD;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
