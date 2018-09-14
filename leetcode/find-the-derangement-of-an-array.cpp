//
//  find-the-derangement-of-an-array
//  https://leetcode.com/problems/find-the-derangement-of-an-array/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDerangement(int n) {
        // 题目：元素i不能在位置i，有多少种排列
        // https://en.wikipedia.org/wiki/Derangement#Counting_derangements
        // 元素1可以换到位置[2..n]，有n-1种选择，比如说换到位置i。
        // 考虑元素i换不换到位置1：如果换到位置1，元素1和i的位置确定，剩下n-2个元素的子问题dp[n-2]；
        // 如果不换到位置1，那么考虑"去除被占用的位置i后的n-1个位置"，元素i在这n-1位置中有个禁止位置（位置1），
        // 其他元素在这n-1位置中也有个禁止位置（本身位置），这就是n-1个元素的子问题dp[n-1]。
        // 所以 dp[n] = (n-1)(dp[n-2]+dp[n-1])
        // 初始dp[1]=0，dp[0]=1（由dp[2]=1推得）
        // dp[n]只依赖于前两项，降维，用prev2表示dp[n-2]，prev1表示dp[n-1]
        const int MOD = 1e9 + 7;
        int prev2 = 1, prev1 = 0;
        for (int i = 2; i <= n; i++) {
            int curr = ((i-1L) * (prev2 + prev1)) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
