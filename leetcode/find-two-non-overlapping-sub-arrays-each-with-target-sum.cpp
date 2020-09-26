//
//  find-two-non-overlapping-sub-arrays-each-with-target-sum
//  https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // 全为正数，可用滑动数组
        // 设dp[i]表示arr[0..i]的、和为target的、最小长度
        // 若找到有效窗口[lo..hi]，dp[hi]=min(hi-lo+1,dp[hi-1])
        // 若没找到，dp[hi]=dp[hi-1]
        const int N = arr.size(), INF = 1e9;
        vector<int> dp(N, INF);
        int sum = 0, ans = INF;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            sum += arr[hi];
            while (sum > target) {
                sum -= arr[lo++];
            }

            if (sum == target) {
                int len = hi - lo + 1;
                dp[hi] = len;
                // 不重叠子段，能求到两个长度最小的
                if (lo > 0) ans = min(ans, len + dp[lo-1]);
            }
            if (hi > 0) dp[hi] = min(dp[hi], dp[hi-1]);
        }
        return ans == INF ? -1 : ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
