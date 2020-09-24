//
//  k-concatenation-maximum-sum
//  https://leetcode.com/problems/k-concatenation-maximum-sum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // 数组重复k次，最大子段和只有两种可能：
        // 1) 一个数组：arr内的maxSum
        // 2) 多个数组：max{arr[..N-1]} + max{(k-2)*arrSum, 0} + max{arr[0..]}
        const int MOD = 1e9 + 7;
        const int N = arr.size();
        int maxEndHere = 0, maxStartHere = 0;
        int maxSum = 0, arrSum = 0;
        for (int i = 0; i < N; i++) {
            maxEndHere = max(maxEndHere + arr[i], 0);
            maxStartHere = max(maxStartHere + arr[N-1-i], 0);
            maxSum = max(maxSum, maxEndHere);
            arrSum += arr[i];
        }
        if (k > 1) {
            int midArrsSum = max(((k - 2) * (long)arrSum) % MOD, 0l);
            maxSum = max(maxSum, maxEndHere + midArrsSum + maxStartHere);
        }
        return maxSum % MOD;
    }
};
int main(int argc, const char * argv[]) {    
    return 0;
}
