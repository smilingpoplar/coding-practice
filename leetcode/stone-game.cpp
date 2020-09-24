//
//  stone-game
//  https://leetcode.com/problems/stone-game/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // 设dp[i][j]表示从piles[i..j]首尾取数的最大得分，自己取数得正分、对手取数得负分
        // dp[i][j] = max{ piles[i] - dp[i+1][j], piles[j] - dp[i][j-1] }，0<=i<=j<N
        // 初始dp[i][i] = piles[i]
        const int N = piles.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) dp[i][i] = piles[i];
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][N-1] > 0;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
