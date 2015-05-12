//
//  search-insert-position
//  https://leetcode.com/problems/search-insert-position/
//
//  Created by smilingpoplar on 15/5/12.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 不变式：nums[l,u]是数组中包含target的部分（l<=u）
        int l = 0;
        int u = (int)nums.size() - 1;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,5,6};
    int target = 7;
    Solution solution;
    cout << solution.searchInsert(nums, target);

    return 0;
}
