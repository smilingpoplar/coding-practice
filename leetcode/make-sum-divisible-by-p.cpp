//
//  make-sum-divisible-by-p
//  https://leetcode.com/problems/make-sum-divisible-by-p/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // 找最短子段和 % p = sum % p
        int mod = 0; // sum%p
        for (int num : nums) {
            mod = (mod + num) % p;
        }
        if (mod == 0) return 0;

        const int N = nums.size();
        unordered_map<int, int> premod = {{0, -1}}; // mod=>idx
        int runningMod = 0;
        int ans = INT_MAX;
        for (int i = 0; i < N; i++) {
            runningMod = (runningMod + nums[i]) % p;
            // 找runningMod-toFind=mod，toFind=runningMod-mod
            int toFind = (runningMod - mod + p) % p;
            if (premod.count(toFind)) {
                ans = min(ans, i - premod[toFind]);
            }
            premod[runningMod] = i; // 保留最右的i，好计算最短子段
        }
        return ans < N ? ans : -1; 
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
