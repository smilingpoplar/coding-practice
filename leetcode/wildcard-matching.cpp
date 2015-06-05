//
//  wildcard-matching
//  https://leetcode.com/problems/wildcard-matching/
//
//  Created by smilingpoplar on 15/6/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        // 递归法
        return isMatch(s, 0, p, 0);
    }
private:
    bool isMatch(const string &s, int si, const string &p, int pi) {
        if (pi == p.size()) return si == s.size();
        
        if (p[pi] == '*') {
            int starCount = 1;
            while (pi + starCount < p.size() && p[pi + starCount] == '*') ++starCount;
            return isMatch(s, si, p, pi + starCount) || // 匹配0次
            (si < s.size() && isMatch(s, si + 1, p, pi));  // 递归匹配多次
        }
        return (si < s.size() && (s[si] == p[pi] || p[pi] == '?')) && isMatch(s, si + 1, p, pi + 1);
    }
};
*/

#include <vector>

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        // 动态规划，设f(i,j)表示s[0,i)和p[0,j)匹配，0<=i<=M，0<=j<=N，则
        // 当 p[j-1]=='*'，i>=1，j>=1
        //     f(i,j) = f(i,j-1) // 匹配0次
        //     f(i,j) = f(i-1,j) // 递归匹配多次
        // 当 p[j-1]!='*'，i>=1，j>=1
        //     f(i,j) = (s[i-1]==p[j-1] || p[j-1]=='?') && f(i-1,j-1)
        
        const int M = (int)s.size();
        const int N = (int)p.size();
        vector<vector<bool>> f(M + 1, vector<bool>(N + 1, false));
        f[0][0] = true;
        for (int j = 1; j <= N && p[j - 1] == '*'; ++j) { // 匹配空串
            f[0][j] = true;
        }
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 1] || f[i - 1][j];
                } else {
                    f[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && f[i - 1][j - 1];
                }
            }
        }
        return f[M][N];
    }
};
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        // 动态规划，设f(i,j)表示s[0,i)和p[0,j)匹配，0<=i<=M，0<=j<=N，则
        // 当 p[j-1]=='*'，i>=1，j>=1
        //     f(i,j) = f(i,j-1) // 匹配0次
        //     f(i,j) = f(i-1,j) // 递归匹配多次
        // 当 p[j-1]!='*'，i>=1，j>=1
        //     f(i,j) = (s[i-1]==p[j-1] || p[j-1]=='?') && f(i-1,j-1)
        // -----------------------------------------------------------
        // 观察递推式可知，当前项只由当前组的前面项f(i,x)或前一组f(i-1,x)的值决定，
        // 可在i的递增循环中使用一维数组f(j)，并用prev[]记录前一组的值
        
        const int M = (int)s.size();
        const int N = (int)p.size();
        vector<bool> f(N + 1, false);
        vector<bool> prev(N + 1, false);
        prev[0] = f[0] = true;
        for (int j = 1; j <= N && p[j - 1] == '*'; ++j) { // 匹配空串
            prev[j] = f[j] = true;
        }
        
        for (int i = 1; i <= M; ++i) {
            f[0] = false;
            for (int j = 1; j <= N; ++j) {
                if (p[j - 1] == '*') {
                    f[j] = f[j - 1] || prev[j];
                } else {
                    f[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && prev[j - 1];
                }
            }
            for (int j = 0; j <= N; ++j) {
                prev[j] = f[j];
            }
        }
        return f[N];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isMatch("aa", "a*");
    
    return 0;
}