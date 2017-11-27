//
//  predict-the-winner
//  https://leetcode.com/problems/predict-the-winner/
//
//  Created by smilingpoplar on 17/11/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) { // 保证下面j-1>=0，这样循环只涵盖N>=2的情况，N==1的情况要注意
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][N-1] >= 0; // 这里N==1的情况刚好涵盖在>=0的判断中
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
