//
//  minimum-score-triangulation-of-polygon
//  https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        // 题目：N-2个三角形，每个得分为三顶点之积，最小化总得分
        // 设dp[i][j]表示子多边形A[i..j]，且有条边连接i~j，
        // i、j间有顶点k（i<k<j），将问题分成三部分：
        // 三角形ikj、子多边形A[i..k]、子多边形A[k..j]
        // dp[i][j] = min( A[i]*A[k]*A[j] + dp[i][k] + dp[k][j] )
        // 遍历时i、j间距离要从小到大
        const int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 3; i >= 0; i--) {
            for (int j = i + 2; j < N; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min( dp[i][j], 
                                A[i]*A[k]*A[j] + dp[i][k] + dp[k][j] );
                }
            }
        }
        return dp[0][N-1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
