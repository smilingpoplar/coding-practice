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
        unordered_map<int, int> mp; // runningSum =>pos
        int runningSum = 0;  // 初始空集和
        mp[runningSum] = -1;
        // 在旧runningSum的集合mp中找runningSum-n*k，要找好多个数
        // 这里的关键在于将全部runningSum%k，状态压缩
        // 就变成在runningSum%k的集合mp中找(runningSum-n*k)%k=runningSum%k的值
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            if (k) runningSum %= k;
            if (mp.find(runningSum) == mp.end()) {
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
