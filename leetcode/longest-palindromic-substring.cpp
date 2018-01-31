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

/*
class Solution {
public:
    string longestPalindrome(string s) {
        // 设dp[i][j]表示s[i..j]是最长回文串，0<=i<=j<N
        // dp[i][j] = s[i]==s[j]&&dp[i+1][j-1]
        // dp[i][j]只依赖下左项，可降维，i从下往上遍历
        // 降维导致上下行合并，要让下左项不受影响，也就是让合并后左边项不受影响，j从右往左遍历
        const int N = s.size();
        vector<bool> dp(N, false);
        int longest = 0;
        string palindrome;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N; j >= i; j--) {
                dp[j] = (s[i] == s[j]);
                if (i + 1 <= j - 1) dp[j] = dp[j] && dp[j-1];

                if (dp[j]) {
                    int length = j - i + 1;
                    if (length > longest) {
                        longest = length;
                        palindrome = s.substr(i, length);
                    }
                }
            }
        }
        return palindrome;
    }
};
*/

class Solution {
public:
    string longestPalindrome(string s) {
        // 从可能的中心往外扩展找回文
        int longest = 0;
        int start;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > longest) {
                longest = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, longest);
    }
    
    int expand(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.longestPalindrome("31232156");
    
    return 0;
}
