//
//  split-array-with-same-average
//  https://leetcode.com/problems/split-array-with-same-average/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        // 把A分成B和C，不妨设B是较小的那个，有1<=k<=N/2
        // B和C的平均数相等，应都等于A的平均数。avgB==avgA, sumB/k==sumA/N, sumB==k*sumA/N
        // 因为sumB是整数，有(k*sumA)%N==0
        // 这就变成子集和问题：从A中找k个数，k满足(k*sumA)%N==0，且k个数的子集和为k*sumA/N

        // 子集和问题是01背包问题
        // 设dp[i][k][v]表示能否从前i个数中取k个数，使子集和等于v。
        // 考虑第i个数，dp[i][k][v] = dp[i-1][k][v]/*不取第i数*/ || dp[i-1][k-1][v-nums[i]] /*取第i数*/
        // 递推式在i这维只依赖于i-1项，可省掉i这一维。
        // 01背包问题，逆序遍历k和v：dp[k][v] = dp[k][v] || dp[k-1][v-nums[i]]
        const int N = A.size();
        int sum = 0;
        for (int num : A) sum += num;
        vector<vector<bool>> dp(N / 2 + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < N; i++) { 
            // 01背包，逆序遍历k和v
            for (int k = min(N/2, i+1); k >= 1; k--) { // 因为i是0-based
                for (int v = sum; v >= A[i]; v--) {
                    dp[k][v] = dp[k][v] || dp[k-1][v-A[i]];
                }
            }
        }
        
        for (int k = 1; k <= N / 2; k++) {
            if (k * sum % N == 0 && dp[k][k * sum / N]) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
