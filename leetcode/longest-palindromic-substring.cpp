//
//  longest-palindromic-substring
//  https://leetcode.com/problems/longest-palindromic-substring/
//
//  Created by smilingpoplar on 15/6/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 动态规划，设f(i,j)表示s[i,j]是回文串，0<=i<=j<=N-1
        // f(i,j) = f(i+1,j-1) && s[i]==s[j]，i+1>j-1时是空串f(i+1,j-1)为true
        // =====================================================================
        // 观察递推式，f(i,j)只依赖于前一组f(i+1,x)，在i的递减循环中设前一组为prev则可降维：
        // f(j) = prev(j-1) && s[i]==s[j]，i+1>j-1时是空串f(i+1,j-1)为true
        const int N = (int)s.size();
        vector<int> f(N, 0);
        vector<int> prev(N, 0);
        int longest = 0;
        string palindrome;
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j < N; ++j) {
                f[j] = (i + 1 > j - 1 || prev[j - 1]) && s[i] == s[j];
                if (f[j]) {
                    int length = j - i + 1;
                    if (length > longest) {
                        longest = length;
                        palindrome = s.substr(i, length);
                    }
                }
            }
            prev.swap(f);
        }
        return palindrome;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.longestPalindrome("31232156");

    return 0;
}
