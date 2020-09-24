//
//  find-minimum-in-rotated-sorted-array
//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;

        int l = 0, r = (int)nums.size() - 1;
        while (l + 1 < r) { // N>=3的情况
            if (nums[l] < nums[r]) return nums[l];

            // 旋转数组对半分，一半旋转一半有序，最小值在旋转那一半
            int mid = l + (r - l) / 2;
            if (nums[l] < nums[mid]) { // 左半有序、右半旋转
                l = mid;
            } else { // nums[l] > nums[mid]，左半旋转
                r = mid;
            }
        }
        
        return min(nums[l], nums[r]);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution solution;
    cout << solution.findMin(nums);
    
    return 0;
}
