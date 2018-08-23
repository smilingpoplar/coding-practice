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
        const int N = nums.size();
        if (N < 3) return false;
        // 当前数左边找最小数
        vector<int> leftMin(N);
        leftMin[0] = nums[0];
        for (int i = 1; i < N; i++) {
            leftMin[i] = min(nums[i], leftMin[i-1]);
        }
        // 当前数右边找小于它的最大数，相当于：从右往左找下一个更大的数
        stack<int> stk;
        for (int j = N - 1; j >= 1; j--) {
            int rMax = INT_MIN;
            while (!stk.empty() && nums[j] > stk.top()) {
                rMax = stk.top();
                stk.pop();
            }
            stk.push(nums[j]); // nums[j]是rMax左边的下一个更大的数、rMax是nums[j]右边小于它的最大数
            
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
