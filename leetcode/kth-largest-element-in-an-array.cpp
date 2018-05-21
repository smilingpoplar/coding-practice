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
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

    int findKthLargest(vector<int>& nums, int l, int u, int k) {
        int p = partition(nums, l, u);
        int order = p - l + 1; // nums[p]是第几大的数
        if (k == order) return nums[p];
        if (k < order) return findKthLargest(nums, l, p - 1, k);
        return findKthLargest(nums, p + 1, u, k - order);
    }

    int partition(vector<int> &nums, int l, int u) {
        if (l >= u) return l;
        // 单向划分，将数组分为>t、<=t、?三段
        int m = l; // m指向第一段末尾、i指向第三段开头
        for (int i = l + 1; i <= u; i++) {
            if (nums[i] > nums[l]) {
                swap(nums[i], nums[++m]);
            }
        }
        swap(nums[m], nums[l]);
        return m;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,1,5,4,3,6};
    Solution solution;
    cout << solution.findKthLargest(nums, 1);
    
    return 0;
}
