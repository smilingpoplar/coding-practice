//
//  interleaving-string.cpp
//  https://leetcode.com/problems/interleaving-string/
//
//  Created by smilingpoplar on 15/5/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 动态规划，设f(i,j)表示s1[0,i)和s2[0,j)能interleaving成s3[0,i+j) (0<=i<=M, 0<=j<=N)
        // 若 s1[i-1] == s3[i+j-1]，则 f(i,j) = f(i-1,j)
        // 若 s2[j-1] == s3[i+j-1]，则 f(i,j) = f(i,j-1)
        // 故 f(i,j) = (s1[i-1] == s3[i+j-1] && f(i-1,j) || (s2[j-1] == s3[i+j-1] && f(i,j-1))
        
        const size_t M = s1.size();
        const size_t N = s2.size();
        if (s3.size() != M + N) return false;
        
        vector<vector<bool>> f(M + 1, vector<bool>(N + 1, false));
        f[0][0] = true;
        for (size_t i = 1; i <= M; i++) {
            if (s1[i - 1] == s3[i - 1]) {
                f[i][0] = f[i - 1][0];
            }
        }
        for (size_t j = 1; j <= N; j++) {
            if (s2[j - 1] == s3[j - 1]) {
                f[0][j] = f[0][j - 1];
            }
        }
        for (size_t i = 1; i <= M; i++) {
            for (size_t j = 1; j <= N; j++) {
                f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
            }
        }
        
        return f[M][N];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    
    return 0;
}
