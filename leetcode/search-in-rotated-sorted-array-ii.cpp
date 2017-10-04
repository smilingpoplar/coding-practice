//
//  search-in-rotated-sorted-array-ii
//  https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//
//  Created by smilingpoplar on 15/5/22.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 旋转数组对半分后，一半是有序数组、一半是旋转数组
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[l] < nums[mid]) { // 左半有序
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] > nums[mid]) { // 右半有序
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else { // nums[l] == nums[mid]，至少半边全是重复元素
                if (nums[mid] != nums[r]) { // 左半全是重复元素，在右半找
                    l = mid + 1;
                } else { // 不知哪边全是重复元素，两边都得找
                    l++;
                    r--;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,4,5,0,1,2,2};
    Solution solution;
    cout << solution.search(nums, 1) << endl;
    
    return 0;
}
