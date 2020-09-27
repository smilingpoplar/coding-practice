//
//  airplane-seat-assignment-probability
//  https://leetcode.com/problems/airplane-seat-assignment-probability/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // 第1人随机选座，1/n概率选对，(n-1)/n概率选错
        // 选错的时候，比如占了第k座，考虑去掉第k座的子问题，
        // 在子问题中，第k人对应第1座（等价于子问题的第1人）
        // 设dp[n]表示第n人选对的概率，第1人选对时他选对，概率1/n；
        // 第1人选错时，有1/n概率占了他的座，有(n-2)/n概率不占他的座
        // dp[n] = 1/n + (n-2)/n * dp[n-1]
        double dp = 1; // i=1
        for (int i = 2; i <= n; i++) {
            dp = 1.0 / i + (i - 2.0) / i * dp;
        }
        return dp;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
