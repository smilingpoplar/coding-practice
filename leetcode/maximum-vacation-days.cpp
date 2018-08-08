//
//  maximum-vacation-days
//  https://leetcode.com/problems/maximum-vacation-days/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        // flights[][]是城市间的邻接矩阵，days[][]查某城市哪一周能玩几天
        // 设dp[i][k]表示当前在城市i、第k周刚开始、从今往后的最大休假日，
        // 这周休假的城市j可能是i或者flights[i]可达的城市，
        // dp[i][k] = max{ days[j][k] + dp[j][k+1] }。初始dp[][K]=0。
        // 递推式k这维只依赖于k+1项，省掉k这维，k仍从右往左遍历
        if (flights.empty() || days.empty()) return 0;
        const int N = flights.size();
        const int K = days[0].size();
        vector<int> dp(N, 0);
        for (int k = K - 1; k >= 0; k--) {
            vector<int> newdp(N, 0);
            for (int i = 0; i < N; i++) {
                newdp[i] = days[i][k] + dp[i]; // 呆城市i
                for (int j = 0; j < N; j++) { // 飞城市j
                    if (flights[i][j] == 0) continue;
                    newdp[i] = max(newdp[i], days[j][k] + dp[j]);
                }
            }
            swap(newdp, dp);
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
