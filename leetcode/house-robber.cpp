//
//  house-robber
//  https://leetcode.com/problems/house-robber/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 设f(i)表示抢了nums[0..i]后的最大值，0<=i<=N-1
        // f(i) = max( nums[i]+f(i-2), f(i-1) ), 设i<0时f(i)==0
        // 看递推式的值只跟前两个值有关，分别用prev2和prev1表示
        int prev2 = 0, prev1 = 0;
        int current = 0;
        for (int i = 0; i < nums.size(); ++i) {
            current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,20,100,2};
    Solution solution;
    cout << solution.rob(nums);
    
    return 0;
}