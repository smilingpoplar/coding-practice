//
//  find-minimum-in-rotated-sorted-array-ii.cpp
//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/* 旋转数组：
 *     /             /
 *    /             /
 *  -/----/-   ----/----
 *       /        /
 *      /        /
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;
        // 不变式：最小值存在于nums[l,r]中
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // 考虑旋转数组时，要同时考虑旋转数组的特例——有序数组，这里要跟数组右端nums[r]比！
            // 原因见：https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
            // 分别考虑<、==、>三种情况
            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else { // nums[mid] == nums[r]
                if (nums[l] == nums[r]) {
                    ++l;
                    --r;
                } else {
                    r = mid;
                }
            }
        }
        
        return nums[l];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,3,1,3};
    Solution solution;
    cout << solution.findMin(nums);
    
    return 0;
}
