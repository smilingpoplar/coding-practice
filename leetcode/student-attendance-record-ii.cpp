//
//  student-attendance-record-ii
//  https://leetcode.com/problems/student-attendance-record-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        // https://discuss.leetcode.com/topic/86526/improving-the-runtime-from-o-n-to-o-log-n
        // 各个条件作dp的一个维度，设dp[i][a][l]表示s[0..i-1]、*至多*有a次A、末尾*至多*有l个连续L的子问题解
        // 原问题求dp[n][1][2]，初始dp[0][][]=1（因为“至多”，所以都是有效状态）
        // dp[i][a][l] = dp[i-1][a-1][2] /*..A*/ + dp[i-1][a][l-1] /*..L*/ + dp[i-1][a][2] /*..P*/
        // dp[i][][]只依赖于dp[i-1][][]，降维
        const int MOD = 1000000007;
        vector<vector<int>> dp(2, vector<int>(3, 1));
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> cur(2, vector<int>(3));
            for (int a = 0; a < 2; ++a) {
                for (int l = 0; l < 3; ++l) {
                    int val = dp[a][2]; // ..P
                    if (a > 0) val = (val + dp[a-1][2]) % MOD; // ..A
                    if (l > 0) val = (val + dp[a][l-1]) % MOD; // ..L
                    cur[a][l] = val;
                }
            }
            swap(dp, cur);
        }
        return dp[1][2];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}