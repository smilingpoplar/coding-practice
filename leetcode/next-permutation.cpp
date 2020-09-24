//
//  next-permutation
//  https://leetcode.com/problems/next-permutation/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 生成"下一排列"：
        // 1. 从右往左找第一个波峰前的数，即找第一个nums[i]<nums[i+1]的位置i
        // 2. 在i右边、从波峰往右是个递减序列，从右往左肯定能找到第一个>nums[i]的位置j
        // 3. 交换nums[i]和nums[j]，交换后从波峰往右仍是个递减序列
        // 4. 反转从波峰往右这个递减序列
        const int N = nums.size();
        int i = N - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = N - 1;
        while (j > i && nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,2};
    Solution solution;
    solution.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    
    return 0;
}
