//
//  longest-palindromic-substring
//  https://leetcode.com/problems/longest-palindromic-substring/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    string longestPalindrome(string s) {
        // 设dp[i][j]表示s[i..j]是否是回文串，0<=i<=j<N
        // dp[i][j] = s[i]==s[j] && dp[i+1][j-1]，
        // dp在i维上只依赖i+1项，可省掉i维，i仍从右往左遍历
        // 要让dp[j-1]表示旧状态dp[i+1][j-1]，j从右往左遍历
        const int N = s.size();
        vector<bool> dp(N, false);
        int longest = 0;
        string ans;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= i; j--) {
                dp[j] = (s[i] == s[j]);
                if (i + 1 <= j - 1) dp[j] = dp[j] && dp[j-1];

                if (dp[j]) {
                    int len = j - i + 1;
                    if (len > longest) {
                        longest = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    string longestPalindrome(string s) {
        // 从可能的中心往外扩展找回文
        int longest = 0, lo = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > longest) {
                longest = len;
                lo = i - (len - 1) / 2;
            }
        }
        return s.substr(lo, longest);
    }
    
    int expand(const string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1; // (l,r)
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.longestPalindrome("31232156");
    
    return 0;
}
