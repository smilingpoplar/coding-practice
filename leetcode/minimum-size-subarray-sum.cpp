//
//  minimum-size-subarray-sum
//  https://leetcode.com/problems/minimum-size-subarray-sum/
//
//  Created by smilingpoplar on 15/5/25.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 保持不变式：nums[left,i]是sum>=s的最小子数组
        const int N = (int)nums.size();
        int ans = INT_MAX;
        int sum = 0;
        int left = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            while (sum >= s) { 
                ans = min(ans, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,1,2,4,3};
    
    Solution solution;
    cout << solution.minSubArrayLen(7, nums);
    
    return 0;
}
