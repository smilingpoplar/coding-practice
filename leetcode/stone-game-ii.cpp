//
//  stone-game-ii
//  https://leetcode.com/problems/stone-game-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // 设dp[i][m]表示从piles[i..]、参数M=m时的得分（能拿的最大石头数）
        // 拿掉前x个后，对手得分dp[i+x][max(m,x)]，最小化对手得分即最大化自己得分，
        // dp[i][m]=max{ sufsum[i] - dp[i+x][max(m,x)] }，1<=x<=2m
        // 初始dp[N][]=0，dp[i][N]=sufsum[i]
        const int N = piles.size();
        vector<int> sufsum(N + 1, 0);
        for (int i = N - 1; i >= 0; i--) {
            sufsum[i] = sufsum[i+1] + piles[i];
        }
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for (int i = 0; i < N; i++) {
            dp[i][N] = sufsum[i];
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int m = N - 1; m >= 1; m--) {
                for (int x = 1; x <= 2 * m && i + x <= N; x++) {
                    dp[i][m] = max(dp[i][m], sufsum[i] - dp[i+x][max(m, x)]);
                }
            }
        }
        return dp[0][1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
