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
        int l = 0, u = (int)nums.size() - 1;
        while (l <= u) {
            int p = partition(nums, l, u); // p跟下标k-1比较，因为第k大数的下标应该是k-1
            if (k - 1 == p) return nums[p];
            if (k - 1 < p) u = p - 1;
            else l = p + 1;
        }
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
