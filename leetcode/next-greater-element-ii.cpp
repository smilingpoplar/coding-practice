//
//  next-greater-element-ii
//  https://leetcode.com/problems/next-greater-element-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ans(N, -1);
        stack<int> stk; // 找下一个更大元素，保存下标
        // 循环数组，查找两遍nums[]
        for (int i = 0; i < 2 * N; i++) {
            while (!stk.empty() && nums[i % N] > nums[stk.top()]) {
                ans[stk.top()] = nums[i % N];
                stk.pop();
            }
            if (i < N) stk.push(i); // 前N个数才找
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
