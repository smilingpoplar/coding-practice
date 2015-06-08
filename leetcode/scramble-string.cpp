//
//  scramble-string
//  https://leetcode.com/problems/scramble-string/
//
//  Created by smilingpoplar on 15/6/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        // 简单递归会超时，因为重复计算了子问题，后面可以用动态规划解决
        // 这里加个剪枝条件（所有字符出现的次数应相同），可以通过测试
        const int ASCII_SIZE = 256;
        vector<int> count(ASCII_SIZE, 0);
        for (char c : s1) ++count[c];
        for (char c : s2) --count[c];
        for (int i = 0; i < ASCII_SIZE; ++i) {
            if (count[i] != 0) return false;
        }
        
        const int N = (int)s1.size();
        for (int i = 1; i < N; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
                (isScramble(s1.substr(0, i), s2.substr(N - i)) && isScramble(s1.substr(i), s2.substr(0, N - i))))
                return true;
        }
        
        return false;
    }
};
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // 动态规划，设f(n,i,j)表示s1[i,i+n)和s2[j,j+n)是否scramble，1<=n<=N，0<=i<=N-n，0<=j<=N-n
        // f(n,i,j) = ( f(k,i,j)&&f(n-k,i+k,j+k) ) || ( f(k,i,j+n-k)&&f(n-k,i+k,j) )，1<=k<n<=N，0<=i<=N-n，0<=j<=N-n

        if (s1.size() != s2.size()) return false;
        const int N = (int)s1.size();
        vector<vector<vector<bool>>> f(N + 1, vector<vector<bool>>(N, vector<bool>(N, false)));
        
        // n==1
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                f[1][i][j] = s1[i] == s2[j];
            }
        }
        
        for (int n = 1; n <= N; ++n) {
            for (int i = 0; i <= N - n; ++i) {
                for (int j = 0; j <= N - n; ++j) {
                    for (int k = 1; k < n; ++k) { // n>=2进循环
                        if ((f[k][i][j] && f[n - k][i + k][j + k]) ||
                            (f[k][i][j + n - k] && f[n - k][i + k][j])) {
                            f[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return f[N][0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isScramble("abc", "acb");

    return 0;
}
