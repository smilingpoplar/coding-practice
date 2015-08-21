//
//  find-minimum-in-rotated-sorted-array.cpp
//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
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
            // 考虑旋转数组时，要同时考虑旋转数组的特例——有序数组，这里较tricky：要跟数组右端nums[r]比！
            // 若跟左端nums[l]比，当nums[mid]>nums[l]时旋转数组要更新l、有序数组要更新r，两者矛盾；而跟右端nums[r]比，不变式总能成立
            // 分别考虑<、==、>三种情况（然后合并情况相同的<和==）
            if (nums[mid] <= nums[r]) {
                r = mid;
            } else { // nums[mid] > nums[r]
                l = mid + 1;
            }
        }
        
        return nums[l];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution solution;
    cout << solution.findMin(nums);
    
    return 0;
}
