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
        // 生成"下一排列"的算法：
        // 1. 从右到左，找到第一个违反递增趋势的数nums[i]，nums[i] < nums[i+1]
        // 2. 从右到左，找到第一个大于nums[i]的数nums[j]，nums[j] > nums[i]
        // 3. 交换nums[i]和nums[j]
        // 4. 反转nums[i+1,N-1]
        const int N = (int)nums.size();
        int i = N - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) break;
            --i;
        }
        if (i < 0) { // 不存在违反递增趋势的数
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = N - 1;
        while (j > i) {
            if (nums[j] > nums[i]) break; // j肯定存在
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
