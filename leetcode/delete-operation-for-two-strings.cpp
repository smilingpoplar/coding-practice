//
//  delete-operation-for-two-strings
//  https://leetcode.com/problems/delete-operation-for-two-strings/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 设dp[i,j]表示word1[i,..]和word2[j,..]的最长公共子序列
        // 初始dp[n1,..]=dp[..,n2]=0，两串字长公共子序列dp[0,0]
        // word1[i]==word2[j] => dp[i,j]=dp[i+1,j+1], 
        //         !=         =>        =max(dp[i,j+1], dp[i+1,j])
        const int n1 = word1.size();
        const int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return n1 + n2 - 2 * dp[0][0];        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}