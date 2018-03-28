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
        // 设dp[i][k]表示当前在城市i、第k周、从今往后的最大假期，下一周的城市j可能是i或者flights[i]可飞的城市，
        // dp[i][k] = max{ days[j][k+1] + dp[j][k+1] }。初始dp[][K]=0。
        // dp[][k]只依赖于dp[][k+1]，降掉k这维，用curr[]表示dp[][k]，next[]表示dp[][k+1]。
        if (flights.empty() || days.empty()) return 0;
        const int N = flights.size();
        const int K = days[0].size();
        vector<int> next(N, 0);
        for (int k = K - 1; k >= 0; k--) {
            vector<int> curr(N, 0);
            for (int i = 0; i < N; i++) {
                curr[i] = days[i][k] + next[i]; // 呆城市i
                for (int j = 0; j < N; j++) {
                    if (flights[i][j] == 0) continue;
                    curr[i] = max(curr[i], days[j][k] + next[j]); // 飞城市j
                }
            }
            swap(curr, next);
        }
        return next[0];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
