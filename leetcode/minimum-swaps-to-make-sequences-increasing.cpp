//
//  minimum-swaps-to-make-sequences-increasing
//  https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        // 设dp[i][0]表示A[0..i]、B[0..i]的A[i]、B[i]没交换时的最小交换数，
        //   dp[i][1]                              交换
        // 如果A[i-1]<A[i]&&B[i-1]<B[i]，如果第i-1项交换、第i项也要交换：dp[i][1] = dp[i-1][1]+1
        //                              第i-1项没交换、第i项也不用交换：dp[i][0] = dp[i-1][0]
        // 如果A[i-1]<B[i]&&B[i-1]<A[i]，如果第i-i项交换、第i项就不用交换：dp[i][0] = dp[i-1][1]
        //                              第i-1项没交换、第i项就要交换：dp[i][1] = dp[i-1][0]+1
        // 上述两种情况可同时存在。初始dp[0][0]=0, dp[0][1]=1
        // dp[i][]只依赖于dp[i-1][]，降维，初始dp[0]=0,dp[1]=1
        const int N = A.size();
        vector<int> prev = {0, 1};
        for (int i = 1; i < N; i++) {
            vector<int> curr = {INT_MAX, INT_MAX};
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                curr[1] = min(curr[1], prev[1] + 1);
                curr[0] = min(curr[0], prev[0]);
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                curr[0] = min(curr[0], prev[1]);
                curr[1] = min(curr[1], prev[0] + 1);
            }
            swap(curr, prev);
        }
        return min(prev[0], prev[1]);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
