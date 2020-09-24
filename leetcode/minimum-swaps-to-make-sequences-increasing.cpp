//
//  minimum-swaps-to-make-sequences-increasing
//  https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        // 设dp[i][0]表示A[0..i]、B[0..i]不交换A[i]、B[i]时的最小交换数，
        //   dp[i][1]                   交换
        // 若A[i-1]<A[i]&&B[i-1]<B[i]，如果交换第i-1项、就要交换第i项：dp[i][1] = dp[i-1][1]+1
        //                            不交换第i-1项、就不用交换第i项：dp[i][0] = dp[i-1][0]
        // 若A[i-1]<B[i]&&B[i-1]<A[i]，如果交换第i-i项、就不用交换第i项：dp[i][0] = dp[i-1][1]
        //                            不交换第i-1项、就要交换第i项：dp[i][1] = dp[i-1][0]+1
        // 上述两种情况可同时存在。
        // 初始dp[0][0]=0, dp[0][1]=1
        // 递推式i这维只依赖i-1项，省掉i这维，i仍从左往右遍历
        const int N = A.size();
        vector<int> dp = {0, 1};
        for (int i = 1; i < N; i++) {
            vector<int> ndp = {INT_MAX, INT_MAX};
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                ndp[1] = min(ndp[1], dp[1] + 1);
                ndp[0] = min(ndp[0], dp[0]);
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                ndp[0] = min(ndp[0], dp[1]);
                ndp[1] = min(ndp[1], dp[0] + 1);
            }
            swap(ndp, dp);
        }
        return min(dp[0], dp[1]);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
