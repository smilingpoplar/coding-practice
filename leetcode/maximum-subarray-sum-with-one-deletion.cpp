//
//  maximum-subarray-sum-with-one-deletion
//  https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // 设dp[i][0]表示以arr[i]结尾、没有删除数的最大和，
        // dp[i][1]表示以arr[i]结尾、删除过一个数的最大和。
        // dp[i][0] = dp[i-1][0]+arr[i]
        // dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i])
        // 第i项只依赖i-1项，省掉i这维，注意赋值顺序，
        // dp[1] = max(dp[0], dp[1]+arr[i])
        // dp[0] = max(dp[0]+arr[i], arr[i])
        const int N = arr.size();
        vector<int> dp({arr[0], 0}); // i==0
        int ans = dp[0]; // 子段要非空
        for (int i = 1; i < N; i++) {
            dp[1] = max(dp[0], dp[1] + arr[i]);
            dp[0] = max(dp[0] + arr[i], arr[i]);
            ans = max({ans, dp[0], dp[1]});
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
