//
//  maximum-subarray
//  https://leetcode.com/problems/maximum-subarray/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // O(n)，可来自dp的降维写法
        int maxendinghere = 0, maxsofar = INT_MIN;
        for (int num : nums) {
            maxendinghere = max(maxendinghere + num, num);
            maxsofar = max(maxsofar, maxendinghere);
        }
        return maxsofar;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray(nums);
    
    return 0;
}
