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
        // 设dp[i]表示以A[i]结尾的等差子段数。
        // 若A[i]-A[i-1]=A[i-1]-A[i-2]时，dp[i]=dp[i-1]+1；
        // 其中dp[i-1]来自扩展的旧子段，1来自新出现的长度==3的子段。
        // 若不满足等差，dp[i]=0。
        // 初始dp[0]=dp[1]=0，因为长度要>=3。
        // i这维只依赖前一项，省掉i这维，满足等差时dp+=1，不满足时dp=0。
        int ans = 0;
        int dp = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp += 1;
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
