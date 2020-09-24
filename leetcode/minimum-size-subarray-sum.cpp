//
//  minimum-size-subarray-sum
//  https://leetcode.com/problems/minimum-size-subarray-sum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int N = nums.size();        
        int sum = 0, ans = INT_MAX;
        for (int hi = 0, lo = 0; hi < N; hi++) {
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
