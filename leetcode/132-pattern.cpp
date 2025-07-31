//
//  132-pattern
//  https://leetcode.com/problems/132-pattern/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 132模式：顺序三个数a1、a2、a3，a1<a3<a2。
        // 对于第二个数a2，在右边找下一个更小的数a3，再看左边是否有数<a3。
        // a2右边下一个更小的数a3 <=等价于=> 从右往左，a3找下一个更大的数a2
        const int N = nums.size();
        int a3 = INT_MIN;
        stack<int> stk;
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] < a3) return true;  // i--后进新循环，nums[i]是a1

            while (!stk.empty() && nums[i] > stk.top()) {  // nums[i]是a2
                a3 = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
