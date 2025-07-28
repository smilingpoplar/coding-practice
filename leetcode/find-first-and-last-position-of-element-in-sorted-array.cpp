//
//  search-for-a-range
//  https://leetcode.com/problems/search-for-a-range/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = lowerBound(nums, target);
        if (pos == nums.size() || nums[pos] != target) return {-1, -1};
        int last = lowerBound(nums, target + 1) - 1;
        return {pos, last};
    }

    int lowerBound(const vector<int>& nums, int target) {
        // 不变式：nums[l] < target <= nums[u]
        int l = -1, u = nums.size();
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] >= target) {
                u = mid;
            } else {
                l = mid;
            }
        }
        return u;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution solution;
    auto result = solution.searchRange(nums, target);
    for (auto index : result) {
        cout << index << " ";
    }

    return 0;
}
