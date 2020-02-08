//
//  binary-subarrays-with-sum
//  https://leetcode.com/problems/binary-subarrays-with-sum/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> presum; // sum=>count
        int runningSum = 0;
        presum[runningSum] = 1; // 初始空集
        
        int ans = 0;
        for (int a : A) {
            runningSum += a;
            // 需S=runningSum-toFind
            int toFind = runningSum - S;
            if (presum.count(toFind)) ans += presum[toFind];
            presum[runningSum]++;
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
