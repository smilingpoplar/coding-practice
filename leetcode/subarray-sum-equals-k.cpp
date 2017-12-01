//
//  subarray-sum-equals-k
//  https://leetcode.com/problems/subarray-sum-equals-k/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int runningSum = 0;
        map<int, int> m; // sum=>count
        m[runningSum] = 1; // 初始空集
        int total = 0;
        for (int num : nums) {
            runningSum += num;
            int toFind = runningSum - k;
            if (m.find(toFind) != m.end()) {
                total += m[toFind];
            }
            m[runningSum]++;
        }
        return total;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
