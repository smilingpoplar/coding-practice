//
//  search-for-a-range
//  https://leetcode.com/problems/search-for-a-range/
//
//  Created by smilingpoplar on 15/5/12.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 分两次分别搜索上下边界
        return {lowerBound(nums, target), upperBound(nums, target)};
    }
private:
    int lowerBound(const vector<int> &nums, int target) {
        // 不变式：
        // | < t | >= t |   &&  l < u (不断缩小范围后最终 l + 1 = u，u可能为下边界)
        // [l          u]
        const int N = (int)nums.size();
        int l = -1;
        int u = N;
        while (l + 1 != u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] < target) {
                l = mid;
            } else {
                u = mid;
            }
        }
        if (u >= N || nums[u] > target) return -1;
        return u;
    }
    
    int upperBound(const vector<int> &nums, int target) {
        // 不变式：
        // | <= t | > t |   &&  l < u (不断缩小范围后最终 l + 1 == u，l可能为上边界)
        // [l          u]
        const int N = (int)nums.size();
        int l = -1;
        int u = N;
        while (l + 1 != u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                u = mid;
            }
        }
        if (l <= -1 || nums[l] < target) return -1;
        return l;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution solution;
    auto result = solution.searchRange(nums, target);
    for (auto index : result) {
        cout << index << " ";
    }
    
    return 0;
}
