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
    int findMin(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;
        // 不变式：最小值在nums[l,r]中
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // 要跟右端点nums[r]比较，原因参见：search-in-rotated-sorted-array
            if (nums[mid] > nums[r]) { // 左半段有序
                l = mid + 1;
            } else if (nums[mid] < nums[r]) { // 右半段有序
                r = mid;
            } else { // nums[mid] == nums[r]，因为 mid < r，这是两个相同的数，可以去掉一个
                --r;
            }
        }
        return nums[l];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,5,5,6,7,7,0,1,2};
    Solution solution;
    cout << solution.findMin(nums);
    
    return 0;
}
