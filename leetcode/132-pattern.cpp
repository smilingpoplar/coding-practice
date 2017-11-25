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
        const int N = (int)nums.size();
        if (N < 3) return false;
        // 左边找最小值
        vector<int> leftMin(N);
        leftMin[0] = INT_MAX;
        for (int i = 1; i < N; i++) {
            leftMin[i] = min(nums[i - 1], leftMin[i - 1]);
        }
        // 右边找小于当前值的最大值，使用栈顶最小的栈
        stack<int> S;
        for (int j = N - 1; j >= 0; j--) {
            int rMax = INT_MIN;
            while (!S.empty() && nums[j] > S.top()) {
                rMax = S.top();
                S.pop();
            }
            S.push(nums[j]);
            if (leftMin[j] < rMax) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = { 3, 1, 4, 2 };
    cout << find132pattern(nums);  
    return 0;
}
