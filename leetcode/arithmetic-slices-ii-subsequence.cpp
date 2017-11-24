//
//  arithmetic-slices-ii-subsequence
//  https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sum = 0;
        int n = A.size();
        vector<map<int,int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long)A[i] - A[j];
                if (d < INT_MIN || d > INT_MAX) continue; // pass OL
                dp[i][d] += dp[j][d] + 1; // 两元素也算序列的“扩展子序列”
                sum += dp[j][d]; // 至少三个元素的子序列                   
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
