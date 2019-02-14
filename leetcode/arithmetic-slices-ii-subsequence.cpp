//
//  arithmetic-slices-ii-subsequence
//  https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // 设dp[i][d]表示以A[i]结尾、等差为d、长度>=2的等差子序列数。
        // 对所有j<i，d=A[i]-A[j]，dp[i][d] += dp[j][d]+1
        // 其中dp[j][d]来自扩展的旧序列，1来自新出现的长度==2序列
        // 初始dp[0][]=0，因为长度要>=2
        // 优化：由于d是两数之差，范围无限，dp[i][d]的d这一维要用unordered_map。
        // 在访问dp[j][d]前要用dp[j].count(d)测试，防止d值不存在时往map里添0，内存溢出。
        const int N = A.size();
        vector<unordered_map<int,int>> dp(N);
        int ans = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long)A[i] - A[j];
                if (d < INT_MIN || d > INT_MAX) continue; // pass OL
                int dp_jd = dp[j].count(d) ? dp[j][d] : 0; // 防止d值不存在时往map里添0
                dp[i][d] += dp_jd + 1; // dp[j][d]是扩展的旧序列，现在长度>=3
                ans += dp_jd; // 统计长度>=3的
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
