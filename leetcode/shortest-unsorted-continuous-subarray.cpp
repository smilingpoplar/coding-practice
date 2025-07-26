//
//  shortest-unsorted-continuous-subarray
//  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 若数组有序，对任意nums[i]有：maxL[i]==nums[i]==minR[i]
        // 从左往右检查，最右的违反maxL[i]==nums[i]的i是右边界
        // 从右往左检查，最左的违反nums[i]==minR[i]的i是左边界
        const int N = nums.size();
        int maxL = INT_MIN, minR = INT_MAX;
        int lo = 0, hi = -1;  // 无序子段的左右边界
        for (int i = 0, j = N - 1; i < N; i++, j--) {
            maxL = max(maxL, nums[i]);
            if (nums[i] != maxL) hi = i;

            minR = min(minR, nums[j]);
            if (nums[j] != minR) lo = j;
        }
        return hi - lo + 1;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
