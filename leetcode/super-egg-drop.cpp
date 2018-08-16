//
//  super-egg-drop
//  https://leetcode.com/problems/super-egg-drop/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        // 设dp[k][m]表示k个鸡蛋m个步骤、最多能确定的楼层数。
        // 在某层扔鸡蛋，如果碎了，能确定下面的dp[k-1][m-1]层；
        // 如果没碎，除了确定自身这1层，还能确定上面的dp[k][m-1]层。
        // 所以，dp[k][m]=dp[k-1][m-1]+dp[k][m-1]+1
        // 初始dp[0][m]=0, dp[k][0]=0
        // 递推式在m这维上只依赖m-1项，可省掉m这维，m仍从左往右遍历
        // 要dp[k-1]表示旧状态dp[k-1][m-1]，k从右往左遍历
        vector<int> dp(K + 1);
        int m = 0;
        dp[K] = 0; // m==0
        while (dp[K] < N) {
            m++;
            for (int k = K; k >= 1; k--) {
                dp[k] = dp[k-1] + dp[k] + 1;
            }
        }
        return m;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
