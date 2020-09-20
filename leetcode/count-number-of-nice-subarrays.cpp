//
//  count-number-of-nice-subarrays
//  https://leetcode.com/problems/count-number-of-nice-subarrays/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);        
    }
    
    int atMost(vector<int> &nums, int k) {
        const int N = nums.size();        
        int ans = 0, oddCnt = 0;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (nums[hi] % 2 == 1) oddCnt++;
            while (oddCnt > k) {
                if (nums[lo] % 2 == 1) oddCnt--;
                lo++;
            }
            ans += hi - lo + 1; // [lo,hi], [lo+1,hi], ..., [hi,hi]
        }
        return ans;
    }
};

/*
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 奇数变成1，偶数变成0，题目变成：求子段和为k的子段数
        const int N = nums.size();
        for (auto &num : nums) {
            num = num % 2 == 1 ? 1 : 0;
        }
        
        unordered_map<int, int> presum; // sum=>count
        int runningSum = 0;
        presum[runningSum] = 1; // 初始空集

        int ans = 0;
        for (int num : nums) {
            runningSum += num;
            // 需k=runningSum-toFind
            int toFind = runningSum - k;
            if (presum.count(toFind)) ans += presum[toFind];
            presum[runningSum]++;
        }
        return ans;        
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
