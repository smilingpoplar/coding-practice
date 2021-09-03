//
//  find-k-th-smallest-pair-distance
//  https://leetcode.com/problems/find-k-th-smallest-pair-distance/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // 两数的距离与数的位置无关，先排序数组
        sort(nums.begin(), nums.end());
        // 猜第k小的距离m，m的值范围[0, max(nums)-min(nums)]
        int l = 0, u = nums.back() - nums[0];
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
        // count(m){ <=m的距离个数 }是关于m的递增函数，
        // enough(m){ count(m)>=k }满足二分搜索的条件形式[0..0 1..1]
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
