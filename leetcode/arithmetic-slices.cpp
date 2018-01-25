//
//  arithmetic-slices
//  https://leetcode.com/problems/arithmetic-slices/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // 设dp[i]表示A[0..i]以A[i]结尾的等差数列数，
        // 当A[i]-A[i-1]=A[i-1]-A[i-2]时，dp[i]=dp[i-1]+1；否则，dp[i]=0。初始dp[1]=0
        int ans = 0;
        int dp = 0;
        for (int i = 2; i < A.size(); i++) {
          if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
              dp = dp + 1;
              ans += dp;
          } else {
              dp = 0;
          }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
