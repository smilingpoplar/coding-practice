//
//  132-pattern
//  https://leetcode.com/problems/132-pattern/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 132模式：按顺序的三个数a1、a2、a3，第一数最小、第二数最大，a1<a3<a2。
        // 固定第二个数a2，看它左边的最小数、右边小于它的最大数能否满足条件。
        const int N = nums.size();
        if (N < 3) return false;
        // 先计算某数（含）左边的最小数
        vector<int> leftMin(N);
        leftMin[0] = nums[0];
        for (int i = 1; i < N; i++) {
            leftMin[i] = min(nums[i], leftMin[i-1]);
        }
        // 某数右边小于它的最大数 =转为=> 从右往左找下一个更大的数
        // 不是等价命题，但这题可转。
        // 因为递减栈刚开始的数最大，如果小于它的最大数都不满足条件，其他更不行。
        stack<int> stk;
        for (int j = N - 1; j >= 1; j--) {
            int rMax = INT_MIN;
            while (!stk.empty() && nums[j] > stk.top()) {
                rMax = stk.top();
                stk.pop();
            }
            stk.push(nums[j]);
            
            if (leftMin[j-1] < rMax) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = { 3, 1, 4, 2 };
    cout << find132pattern(nums);  
    return 0;
}
