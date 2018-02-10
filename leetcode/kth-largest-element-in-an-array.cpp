//
//  kth-largest-element-in-an-array
//  https://leetcode.com/problems/kth-largest-element-in-an-array/
//
//  Created by smilingpoplar on 15/6/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }

    int findKthLargest(vector<int>& nums, int k, int l, int u) {
        int p = partition(nums, l, u);
        int order = p - l + 1; // nums[p]是第几大的数
        if (k == order) return nums[p];
        if (k < order) return findKthLargest(nums, k, l, p - 1);
        return findKthLargest(nums, k - order, p + 1, u);
    }

    int partition(vector<int> &nums, int l, int u) {
        if (l >= u) return l;
        // 单向划分，将数组分为>t、<=t两段
        int i = l + 1, j = u; // i指向>t的待写入部分，j指向<=t的待写入部分
        while (i <= j) {
            if (nums[i] > nums[l]) {
                ++i;
            } else {
                swap(nums[i], nums[j]);
                --j;
            }
        }
        swap(nums[j], nums[l]);
        return j;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,1,5,4,3,6};
    Solution solution;
    cout << solution.findKthLargest(nums, 1);
    
    return 0;
}
