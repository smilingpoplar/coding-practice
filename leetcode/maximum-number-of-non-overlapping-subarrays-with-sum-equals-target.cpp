//
//  maximum-number-of-non-overlapping-subarrays-with-sum-equals-target
//  https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        const int N = nums.size();
        // 判断重叠，使用sum=>idx、记录lastIdx
        unordered_map<int, int> presum = {{0, -1}}; // sum=>idx
        int runningSum = 0, lastIdx = -1, ans = 0;
        for (int i = 0; i < N; i++) {
            runningSum += nums[i];
            // runningSum-toFind=target
            int toFind = runningSum - target;
            if (presum.count(toFind)) {
                // 保证不重叠，presum相关是前开后闭区间
                if (presum[toFind] >= lastIdx) {
                    ans++;
                    lastIdx = i;
                }
            }
            // 多个相同值保留最右的，因为前面的已处理过
            presum[runningSum] = i;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
