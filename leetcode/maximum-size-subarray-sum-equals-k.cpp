//
//  maximum-size-subarray-sum-equals-k
//  https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, -1}};  // sum=>firstIdx
        int runningSum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            int toFind = runningSum - k;
            if (mp.count(toFind)) ans = max(ans, i - mp[toFind]);
            if (!mp.count(runningSum)) mp[runningSum] = i;  // 相同sum记录最小的idx
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
