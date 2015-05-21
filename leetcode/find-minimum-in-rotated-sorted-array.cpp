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
            // 这里要跟数组右端nums[r]比。因为子数组可能是有序数组（旋转数组的特例），
            // 当跟左端nums[l]比时，l更新后不变式可能在有序数组中不成立，而跟右端nums[r]比时不变式总能成立
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
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
