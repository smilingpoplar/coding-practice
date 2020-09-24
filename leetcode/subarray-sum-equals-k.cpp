//
//  subarray-sum-equals-k
//  https://leetcode.com/problems/subarray-sum-equals-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt; // sum=>count
        int runningSum = 0;
        cnt[runningSum] = 1; // 初始空集

        int ans = 0;
        for (int num : nums) {
            runningSum += num;
            int toFind = runningSum - k;
            if (cnt.count(toFind)) {
                ans += cnt[toFind];
            }
            cnt[runningSum]++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
