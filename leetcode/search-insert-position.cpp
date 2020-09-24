//
//  search-insert-position
//  https://leetcode.com/problems/search-insert-position/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 找>=target的第一个位置
        int l = 0, u = (int)nums.size() - 1;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
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
