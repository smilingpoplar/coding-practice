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
        unordered_map<int, int> m;
        int runningSum = 0;
        m[runningSum] = -1; // 初始空集对应map
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            if (k) runningSum %= k;
            if (m.find(runningSum) != m.end()) {
                if (i - m[runningSum] >= 2) return true;
            } else {
                m[runningSum] = i;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
