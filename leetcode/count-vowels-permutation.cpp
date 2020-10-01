//
//  count-vowels-permutation
//  https://leetcode.com/problems/count-vowels-permutation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        const vector<vector<int>> moves = { // aeiou
            {1}, {0,2}, {0,1,3,4}, {2,4}, {0}
        };
        const int M = moves.size();
        // 设dp[i][c]表示使用i个数、最后一个数是c
        // dp[i][dst] = sum{ dp[i-1][src] }
        // 或者对某个dp[i-1][src]，将其累加到各个dp[i][dst]
        // 省掉i这维，用临时遍历变量ndp，ndp[dst]+=dp[src]
        vector<long> dp(M, 1); // i==1
        for (int i = 2; i <= n; i++) {
            vector<long> ndp(M);
            for (int c = 0; c < M; c++) { // src
                for (int nc : moves[c]) { // dst
                    ndp[nc] = (ndp[nc] + dp[c]) % MOD;
                }
            }
            swap(dp, ndp);
        }
        long ans = 0;
        for (int i = 0; i < M; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
