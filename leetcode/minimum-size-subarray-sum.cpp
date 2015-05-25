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
        // 伸缩窗口法，不变式：nums[i,j)是索引i开始的sum>=s的最小子数组
        const int N = (int)nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while (i < N) {
            while (j < N && sum < s) {
                sum += nums[j];
                ++j;
            }
            if (sum >= s) {
                minLen = min(minLen, j - i);
            }
            sum -= nums[i];
            ++i;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,1,2,4,3};
    
    Solution solution;
    cout << solution.minSubArrayLen(7, nums);
    
    return 0;
}
