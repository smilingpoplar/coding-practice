//
//  largest-sum-of-averages
//  https://leetcode.com/problems/largest-sum-of-averages/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        // 设dp[i][k]表示对A[0..i]最多分k段时的最大得分
        // dp[i][k] = max{avg(0..i)/*不分段*/, dp[j][k-1] + avg(j+1..i) }，0<=j<i
        // avg(j+1..i)用前缀和数组计算：(sum[i]-sum[j])/(i-j)，sum[i]表示A[0..i]的和
        // dp[][k]只依赖于dp[][k-1]，省掉k这一维；dp[i]由dp[j]们计算，0<=j<i，i要逆序遍历
        const int N = A.size();
        vector<double> sum(N, 0);
        int runningSum = 0;
        for (int i = 0; i < N; i++) {
            runningSum += A[i];
            sum[i] = runningSum;
        }
        vector<double> dp(N, 0);
        for (int i = 0; i < N; i++) {
            dp[i] = sum[i] / (i + 1); // 不分段k=1
        }
        for (int k = 0; k < K - 1; k++) { // 最多再分K-1次
            for (int i = N - 1; i >= 0; i--) {
                for (int j = 0; j < i; j++) {
                    dp[i] = max(dp[i], dp[j] + (sum[i] - sum[j]) / (i - j));
                }            
            }
        }
        return dp[N-1];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
