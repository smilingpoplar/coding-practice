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
        // 132模式：顺序三个数a1、a2、a3，a1<a3<a2。
        // 固定第二个数，在右边找小于它的最大数rMax，再看左边是否有数<rMax。
        // 某数右边小于它的最大数 <=等价于=> 从右往左找下一个更大的数
        const int N = nums.size();
        if (N < 3) return false;
        
        int rMax = INT_MIN;
        stack<int> stk;
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] < rMax) return true;
            while (!stk.empty() && nums[i] > stk.top()) {
                rMax = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = { 3, 1, 4, 2 };
    cout << find132pattern(nums);  
    return 0;
}
