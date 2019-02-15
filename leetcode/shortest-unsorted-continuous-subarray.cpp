//
//  shortest-unsorted-continuous-subarray
//  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 若数组有序，任意nums[i]有：leftMax[i]==nums[i]==rightMin[i]
        // 从左往右检查，最右的违反leftMax[i]==nums[i]的i，是无序子段的右边界
        // 从右往左检查，最左的违反num[i]==rightMin[i]的i，是无序子段的左边界
        const int N = nums.size();
        int leftMax = INT_MIN, rightMin = INT_MAX;
        int l = 0, r = -1; // 无序子段的左右边界
        for (int i = 0, j = N - 1; i < N; i++, j--) {
            leftMax = max(leftMax, nums[i]);
            if (nums[i] != leftMax) r = i;
            
            rightMin = min(rightMin, nums[j]);
            if (nums[j] != rightMin) l = j;
        }
        return r - l + 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
