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
        // 滑动窗口nums[lo,hi]是sum>=s的子段
        const int N = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        for (int lo = 0, hi = 0; hi < N; hi++) {
            sum += nums[hi];
            while (sum >= s) { 
                ans = min(ans, hi - lo + 1);
                sum -= nums[lo];
                lo++;
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
