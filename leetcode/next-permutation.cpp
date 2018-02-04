//
//  next-permutation
//  https://leetcode.com/problems/next-permutation/
//
//  Created by smilingpoplar on 15/5/28.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 生成"下一排列"：
        // 1. 从右往左看，找第一个峰顶下来的数，即第一个递减的数nums[i]<nums[i+1]
        // 2. nums[i]跟它后面刚好稍大的数交换，因为从右往左看后面是个递增序列，找第一个nums[j]>nums[i]
        // 3. 交换nums[i]和nums[j]，交换后nums[i+1..]的增减特征不变
        // 4. 反转nums[i+1..]以排序
        const int N = nums.size();
        int i = N - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) { // 后面全是从右往左看的递增序列
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = N - 1;
        while (j > i && nums[j] <= nums[i]) {
            --j;
        }
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
