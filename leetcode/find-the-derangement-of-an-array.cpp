//
//  find-the-derangement-of-an-array
//  https://leetcode.com/problems/find-the-derangement-of-an-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDerangement(int n) {
        // 题目：元素k不能在位置k，有多少种排列？
        // https://en.wikipedia.org/wiki/Derangement#Counting_derangements
        // 设dp[i]表示[1..i]的错排数。元素1可以换到位置[2..i]，有i-1种选择，比如说换到位置k。
        // 考虑元素k换不换到位置1：如果换到位置1，元素1和k的位置确定，剩下i-2个元素的子问题dp[i-2]；
        // 如果不换到位置1，那么考虑"去掉被占用的位置k外的i-1个位置"，元素k在这i-1位置中有个禁止位置（位置1），
        // 其他元素在这i-1位置中也有个禁止位置（自身位置），这就是i-1个元素的子问题dp[i-1]。
        // 所以 dp[i] = (i-1) * (dp[i-2] + dp[i-1])
        // 初始dp[1]=0，dp[0]=1（由dp[2]=1推得）
        // dp[i]只依赖于前两项，降维，用prev2表示dp[i-2]，prev1表示dp[i-1]
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
