//
//  contiguous-array
//  https://leetcode.com/problems/contiguous-array/
//
//  Created by smilingpoplar on 17/11/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m; // sum=>index
        int runningSum = 0;
        m[runningSum] = -1; // 初始空集

        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i] == 0 ? -1 : 1;
            if (m.find(runningSum) != m.end()) {
                maxlen = max(maxlen, i - m[runningSum]);
            } else {
                m[runningSum] = i;
            }
        }
        return maxlen;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
