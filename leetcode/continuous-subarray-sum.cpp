//
//  continuous-subarray-sum
//  https://leetcode.com/problems/continuous-subarray-sum/
//
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
        // 子段和是k的倍数，即子段和(runningSum-toFind)%k==0
        // (toFind==runningSum)%K
        // 为让子段尽量长，多个相同runningSum的只保留第一个
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            if (k) runningSum %= k;
            if (!mp.count(runningSum)) {
                mp[runningSum] = i;
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
