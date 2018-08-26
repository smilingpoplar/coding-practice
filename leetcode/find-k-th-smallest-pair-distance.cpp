//
//  find-k-th-smallest-pair-distance
//  https://leetcode.com/problems/find-k-th-smallest-pair-distance/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // 距离m在值范围[0, max(nums)-min(nums)]
        // m越小、<=m的距离个数越小；m越大、<=m的距离个数越大
        // 二分搜索要返回[0 0 ... 0 1 1 ...]，
        // 设二分搜索条件enough(m)表示"<=m的距离个数"count>=k
        sort(nums.begin(), nums.end());
        int l = 0, u = nums[nums.size() - 1] - nums[0];
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (enough(mid, nums, k)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    bool enough(int m, vector<int> &nums, int k) {
        int count = 0;
        for (int j = 1; j < nums.size(); j++) {
            // 找 nums[j]-nums[i] <= m，nums[i] >= nums[j]-m
            int i = lower_bound(nums.begin(), nums.end(), nums[j] - m) - nums.begin();
            count += j - i; // 距离对：(i,j),(i+1,j),...,(j-1,j)
        }
        return count >= k;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
