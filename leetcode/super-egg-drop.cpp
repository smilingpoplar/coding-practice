//
//  super-egg-drop
//  https://leetcode.com/problems/super-egg-drop/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        // 设dp[m][k]表示m个步骤k个鸡蛋、最坏情况下、最多能检查的楼层数。
        //  若鸡蛋碎，往下还能检查n1=dp[m-1][k-1]层。为了保证最坏情况下也能检查最多的楼层，不管碎不碎，一定要在第n1+1层扔；
        //  若鸡蛋不碎，往上还能检查n2=dp[m-1][k]层，这时最多能检查n1+1+n2层。
        // 所以，最坏情况下 dp[m][k] = dp[m-1][k-1] + 1 + dp[m-1][k]
        // 初始dp[m][0]=0, dp[0][k]=0
        // 递推式在m维只依赖m-1项，可省掉m这维，m仍从左往右遍历；要dp[k-1]表示旧状态，k从右往左遍历
        // dp[k] += dp[k-1] + 1
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++) {
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
