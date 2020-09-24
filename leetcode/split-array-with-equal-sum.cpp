//
//  split-array-with-equal-sum
//  https://leetcode.com/problems/split-array-with-equal-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool splitArray(vector<int>& nums) {
        // 题目：除掉i、j、k，数组分成非空的四段，且这四段的和相等        
        const int N = nums.size();
        vector<int> sum(N, 0); // 用累加数组
        sum[0] = nums[0];
        for (int i = 1; i < N; i++)
            sum[i] = sum[i-1] + nums[i];

        // 遍历j的各个取值
        for (int j = 3; j <= N - 4; j++) {
            // j之前存在不同分法的相等小段，用个set记录，而不是单个int。
            // 比如`3,2,1,-1,6`，i分在1时两边小段和为5，分在-1时两边小段和为6。
            unordered_set<int> subSums;
            for (int i = 1; i <= j - 2; i++) {
                if (sum[i-1] == sum[j-1] - sum[i]) {
                    subSums.insert(sum[i-1]);
                }
            }
            if (subSums.empty()) continue;
            // j之后存在与前面相等的小段
            for (int k = j + 2; k <= N - 2; k++) {
                int subSum = sum[k-1] - sum[j];
                if (subSum == sum[N-1] - sum[k] && subSums.count(subSum)) 
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
