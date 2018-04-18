//
//  maximum-size-subarray-sum-equals-k
//  https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // sum=>idx，相同sum记录最小的idx
        int runningSum = 0;
        mp[runningSum] = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            int toFind = runningSum - k;
            if (mp.count(toFind)) ans = max(ans, i - mp[toFind]);
            if (!mp.count(runningSum)) mp[runningSum] = i; // 相同sum记录最小的idx
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
