//
//  maximum-sum-of-two-non-overlapping-subarrays
//  https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int l1, int l2) {
        // 题目：两个不重叠子段，l1在l2前、或l2在l1前
        const int N = A.size();
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            presum[i + 1] = presum[i] + A[i];
        }

        int l1max = 0, l2max = 0, ans = 0;
        for (int i = l1 + l2; i <= N; i++) {
            // l1在l2前
            l1max = max(l1max, presum[i - l2] - presum[i - l1 - l2]);
            ans = max(ans, l1max + (presum[i] - presum[i - l2]));
            // l2在l1前
            l2max = max(l2max, presum[i - l1] - presum[i - l1 - l2]);
            ans = max(ans, l2max + (presum[i] - presum[i - l1]));
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
