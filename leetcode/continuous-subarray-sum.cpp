//
//  continuous-subarray-sum
//  https://leetcode.com/problems/continuous-subarray-sum/
//
//  Created by smilingpoplar on 17/11/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // sum=>idx
        int runningSum = 0;
        mp[runningSum] = -1; // 初始空集
        // 在旧runningSum的集合中找runningSum-n*k，要找好多个数。
        // 这里的关键在于将所有runningSum状态压缩成runningSum%k，
        // 变成在runningSum%k的集合中找(runningSum-n*k)%k=runningSum%k
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            if (k) runningSum %= k;
            if (!mp.count(runningSum)) {
                mp[runningSum] = i; // 相同sum保留第一个
            } else if (i - mp[runningSum] >= 2) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
