//
//  reverse-pairs
//  https://leetcode.com/problems/reverse-pairs/
//
//  Created by smilingpoplar on 17/11/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ans(N, -1);
        stack<int> s; // 找下一个更大元素，用栈，保存下标
        // 循环数组，重复处理两次nums
        for (int i = 0; i < 2 * N; i++) {
            while (!s.empty() && nums[i % N] > nums[s.top()]) {
                ans[s.top()] = nums[i % N];
                s.pop();
            }
            if (i < N) s.push(i); // 压栈的数都会在弹出时找到下一个更大元素，前N个数才找
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
