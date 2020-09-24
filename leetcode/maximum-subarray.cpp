//
//  maximum-subarray
//  https://leetcode.com/problems/maximum-subarray/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = 0, ans = INT_MIN;
        for (int num : nums) {
            currMax = num + max(currMax, 0);
            ans = max(ans, currMax);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray(nums);
    
    return 0;
}
