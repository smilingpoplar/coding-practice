//
//  palindrome-partitioning-ii
//  https://leetcode.com/problems/palindrome-partitioning-ii/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        // 设f(i,j)表示s[i,j]是parlindrome，0<=i<=j<=N-1，则
        // f(i,j) = s[i]==s[j] && f(i+1,j-1), 当j-i>=2
        // f(i,j) = s[i]==s[j], 当j-i==1
        // f(i,j) = true, 当j-i==0
        const int N = (int)s.size();
        vector<vector<bool>> f(N, vector<bool>(N, 0));
        for (int i = 0; i < N; ++i) {
            f[i][i] = true;
        }
        for (int i = 0; i < N - 1; ++i) {
            f[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int distance = 2; distance < N; ++distance) {
            for (int i = 0; i < N - distance; ++i) {
                int j = i + distance;
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }
        // 设cut(i)表示s[0,i]的minCut，0<=i<=N-1，则
        // cut(i) = 0，当f(0,i)==true
        // cut(i) = min( cut(k)+1 )，当f(0,i)==false，f(k+1,i)==true，0<=k<=i-1
        vector<int> cut(N, INT_MAX);
        for (int i = 0; i < N; ++i) {
            if (f[0][i]) {
                cut[i] = 0;
            } else {
                for (int k = 0; k < i; ++k) {
                    if (f[k + 1][i]) {
                        cut[i] = min(cut[i], cut[k] + 1);
                    }
                }
            }
        }
        return cut[N - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.minCut("aab");
    
    return 0;
}