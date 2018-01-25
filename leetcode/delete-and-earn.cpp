//
//  delete-and-earn
//  https://leetcode.com/problems/delete-and-earn/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> count;
        for (int num : nums) count[num]++;
        const int N = 10000;
        // 设dp[i]表示值范围[1..i]的最大得分，i<=1<=N
        // dp[i] = max(dp[i-2] + i*count[i] /*取i*/, dp[i-1] /*不取i*/)
        // dp[i]只依赖前两项，记为prev2、prev1
        int prev2 = 0, prev1 = 0;
        for (int i = 1; i <= N; i++) {
            int curr = max(prev2 + i * count[i], prev1) ;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
