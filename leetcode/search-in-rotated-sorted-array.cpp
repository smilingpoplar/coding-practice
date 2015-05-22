//
//  search-in-rotated-sorted-array
//  https://leetcode.com/problems/search-in-rotated-sorted-array/
//
//  Created by smilingpoplar on 15/5/22.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 不变式：target在nums[l,r]中
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[l]) { // 前半段有序
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else { // 后半段有序
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution solution;
    cout << solution.search(nums, 1) << endl;
    cout << solution.search(nums, 3) << endl;
    
    return 0;
}
