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
        // dp[i][k] = max{ avg(0..i)/*不分段*/, dp[j][k-1] + avg(j+1..i) }，0<=j<i
        // avg(j+1..i)用累加数组计算：(sum[i]-sum[j])/(i-j)，sum[i]表示A[0..i]的和
        // 初始dp[i][1]=avg(0..i)
        // 递推式k这维只依赖k-1项，省掉k这维，k仍从左往右遍历；
        // dp[i]由旧状态dp[j]等计算，i从右往左遍历
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
        for (int k = 2; k <= K; k++) {
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
