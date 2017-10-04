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

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;

        int l = 0;
        int r = (int)nums.size() - 1;
        while (l + 1 < r) { // 至少3个元素，mid可以和l比较
            if (nums[l] < nums[r]) return nums[l];
            
            // 旋转数组对半分，一半旋转一半有序
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[l]) { // 左半有序，那么右半旋转
                l = mid;
            } else if (nums[mid] < nums[l]) { // 左半旋转
                r = mid;
            } else { // 某半边全是重复元素，不管nums[mid]==nums[r]成不成立，都不知最小元素在哪边
                l++;
            }
        }
        
        return min(nums[l], nums[r]);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,3,1,3};
    Solution solution;
    cout << solution.findMin(nums);
    
    return 0;
}
