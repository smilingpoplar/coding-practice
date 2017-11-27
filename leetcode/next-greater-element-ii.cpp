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
        vector<int> next(N, -1);
        stack<int> s; // 栈顶最小的栈，保存相应的下标
        // 循环数组，nums重复两次
        for (int i = 0; i < 2 * N; i++) {
            while (!s.empty() && nums[i % N] > nums[s.top()]) {
                next[s.top()] = nums[i % N];
                s.pop();
            }
            if (i < N) s.push(i); // 前n个数才找next
        }
        return next;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
