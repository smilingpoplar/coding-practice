//
//  delete-and-earn
//  https://leetcode.com/problems/delete-and-earn/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 取数num后删除num-1和num+1，
        // 类似房子抢劫问题，连续值类似于相邻房子
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        const int N = 1e5;  // nums[i]在范围[1..1e5]
        // 设dp[i]表示值范围[1..i]的最大得分，1<=i<=N
        // dp[i] = max(dp[i-2] + i*count[i] /*取i*/, dp[i-1] /*不取i*/)
        // dp[i]只依赖前两项，记前两项为prev2、prev1
        int prev2 = 0, prev1 = 0;
        for (int i = 1; i <= N; i++) {
            int curr = max(prev2 + i * count[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
