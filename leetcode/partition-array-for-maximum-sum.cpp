//
//  partition-array-for-maximum-sum
//  https://leetcode.com/problems/partition-array-for-maximum-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // 设dp[i]表示arr[0..i-1]子问题的最大和
        // dp[i] = max{ dp[i-j]+max(arr[i-j..i-1])*j }, 1<=j<=k
        // 初始dp[0]=0
        // i从左往右遍历
        const int N = arr.size();
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            int maxVal = INT_MIN;
            for (int j = 1, maxJ = min(k, i); j <= maxJ; j++) {
                maxVal = max(maxVal, arr[i-j]);
                dp[i] = max(dp[i], dp[i-j] + maxVal * j);
            }
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
