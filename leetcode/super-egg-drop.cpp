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
        // 设dp[m][k]表示m个步骤k个鸡蛋、最坏情况下、最多检查的楼层数。
        // 假设在第i层扔鸡蛋（i>=1）：
        //  若鸡蛋碎，往下检查要覆盖下面的楼层，dp[m-1][k-1]>=i-1
        //  若鸡蛋不碎，往上检查要覆盖上面的楼层，dp[m-1][k]>=N-i
        // 两式相加，dp[m-1][k-1] + 1 + dp[m-1][k] >= N，覆盖了所有楼层
        // 所以，让 dp[m][k] = dp[m-1][k-1] + 1 + dp[m-1][k] 就能保证找到安全楼层
        // 初始dp[m][0]=0, dp[0][k]=0
        // 递推式在m维只依赖m-1项，可省掉m这维，m仍从左往右遍历
        // 要赋值右边的dp[k-1]表示旧状态，k从右往左遍历
        // dp[k] += dp[k-1] + 1
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++) {
            for (int k = K; k >= 1; k--) {
                dp[k] += dp[k - 1] + 1;
            }
        }
        return m;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
