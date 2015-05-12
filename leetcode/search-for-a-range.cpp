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
        // 不变式：nums[l]<target<=nums[u]（l<u）（即nums[l,u]是数组中包含target的部分）
        // 若初始l=0,u=N-1，因l<u，只处理了N>=2的情况，故引进哨兵nums[-1]<target,nums[N]>=target，设初始l=-1,u=N
        // 当[l,u]范围不断缩小，最终 l + 1 = u，u可能为所求的下边界)
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
        // 不变式：nums[l]<=target<nums[u]（l<u）（即nums[l,u]是数组中包含target的部分）
        // 若初始l=0,u=N-1，因l<u，只处理了N>=2的情况，故引进哨兵nums[-1]<target,nums[N]>=target，设初始l=-1,u=N
        // 当[l,u]范围不断缩小，最终 l + 1 = u，l可能为所求的上边界)
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
