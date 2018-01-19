//
//  maximum-sum-of-3-non-overlapping-subarrays
//  https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if (k * 3 > nums.size()) return { -1, -1, -1 };
        // 所有长k子数组和构成数组W
        vector<int> W(nums.size() - k + 1);
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int w = 0;
        W[w++] = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i-k];
            W[w++] = sum;
        }
        
        // 左边最大和的第一次出现
        vector<int> left(W.size());
        int maxIdx = 0;
        for (int i = 0; i < W.size(); ++i) {
            if (W[i] > W[maxIdx]) {
                maxIdx = i;
            }
            left[i] = maxIdx;
        }
        // 右边最大和的第一次出现
        vector<int> right(W.size());
        maxIdx = W.size() - 1;
        for (int j = W.size() - 1; j >= 0; --j) {
            if (W[j] >= W[maxIdx]) {
                maxIdx = j;
            }
            right[j] = maxIdx;
        }
        
        // 选三个数(ia,ib,ic), ia+k<=ib, ib+k<=ic
        int maxSum = INT_MIN;
        vector<int> ans = { -1, -1, -1 };
        for (int ib = k; ib < W.size() - k; ++ib) {
            int sum = W[left[ib-k]] + W[ib] + W[right[ib+k]];
            if (sum > maxSum) {
                maxSum = sum;
                ans = { left[ib-k], ib, right[ib+k] };
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
