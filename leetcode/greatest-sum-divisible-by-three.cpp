//
//  greatest-sum-divisible-by-three
//  https://leetcode.com/problems/greatest-sum-divisible-by-three/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // 设dp[i][j]表示nums[0..i]最大子集和被3除余j
        // dp[i][j]=max(dp[i-1][j], dp[i-1][(j-nums[i])%3]+nums[i])
        // 第i项只依赖于第i-1项，可省掉i这维，i仍从左往右遍历
        // dp[j]=max(dp[j], dp[(j-num)%3]+num)=max(dp[j], dp[(j+2*num)%3]+num)
        vector<int> dp({0, INT_MIN, INT_MIN});
        for (int num : nums) {
            vector<int> ndp(3);
            for (int j = 0; j < 3; j++) {
                ndp[j] = max(dp[j], dp[(j+2*num)%3] + num);
            }
            swap(dp, ndp);
        }
        return dp[0];                            
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
