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
        // 设dp[m][k]表示m个步骤k个鸡蛋、最多能确定的楼层数。
        // 从某层X扔鸡蛋，扔的时候不知道会不会碎，要考虑会碎的最坏情况，X不能定得太高，
        // X下面最多dp[m-1][k-1]层，X是第dp[m-1][k-1]+1层；
        // 然后考虑没碎的最好情况，还能往上确定dp[m-1][k]层。
        // 因此，dp[m][k] = dp[m-1][k-1] + 1 + dp[m-1][k]
        // 初始dp[m][0]=0, dp[0][k]=0
        // 递推式在m维只依赖m-1项，可省掉m这维，m仍从左往右遍历
        // 要dp[k-1]表示旧状态，k从右往左遍历
        // dp[k] += dp[k-1] + 1
        vector<int> dp(K + 1);
        dp[K] = 0; // m==0
        int m = 0;
        while (dp[K] < N) {
            m++;
            for (int k = K; k >= 1; k--) {
                dp[k] += dp[k-1] + 1;
            }
        }
        return m;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
