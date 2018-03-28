//
//  paint-fence
//  https://leetcode.com/problems/paint-fence/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 题目：no 3 adjacent posts have the same color
    int numWays(int n, int k) {
        // 漆第i新杆时，根据前两根杆同色或不同色分情况讨论。
        // 设最后两根同色的子问题上色方式数为dp[i][0]
        //        不同色                dp[i][1]
        // 若新杆与前一根同色，则前两根不能同色，dp[i][0] = dp[i-1][1]
        // 新杆与前一根不同色，则前两根颜色无所谓，新杆选一种不同色就行
        // dp[i][1] = (dp[i-1][0] + dp[i-1][1]) * (k-1)
        // dp[i][]只依赖于dp[i-1][]，降维
        if (n == 0) return 0;
        if (n == 1) return k;
        vector<int> dp = { k, k * (k - 1) }; // n==2的情况
        for (int i = 3; i <= n; i++) {
            dp = { dp[1],  (dp[0] + dp[1]) * (k - 1)};
        }
        return dp[0] + dp[1];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
