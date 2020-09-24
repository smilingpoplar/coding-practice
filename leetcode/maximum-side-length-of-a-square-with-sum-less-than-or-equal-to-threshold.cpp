//
//  maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
//  https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int M = mat.size(), N = mat[0].size();
        vector<vector<int>> sum(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                // sum[i][j]放[0..i),[0..j)区域的和
                sum[i][j] = sum[i-1][j] + sum[i][j-1]
                    - sum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        int len = 1, ans = 0;
        for (int i = len; i <= M; i++) {
            for (int j = len; j <= N; j++) {
                // 求[i-len..i),[j-len..j)区域的和
                while (i >= len && j >= len 
                       && sum[i][j] - sum[i-len][j] - sum[i][j-len] 
                        + sum[i-len][j-len] <= threshold) {
                    ans = len++;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
