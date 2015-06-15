//
//  shortest-palindrome
//  https://leetcode.com/problems/shortest-palindrome/
//
//  Created by smilingpoplar on 15/6/15.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        // 在s前面添加最少字符构成回文串，得看s的最长回文前缀有多长，
        // 也就是看s#s'的最长边界有多长，边界指同时是前缀和后缀的子串，#是某分隔符，s’是s的反转串，
        // 用KMP的预处理算法，设b[i]表示长为i的前缀的边界长，
        // 不变式：i为前缀长，j为前缀的边界长，
        // 1. 若s[i]==s[j]，当前边界可向右扩展1个字符
        // 2. 若s[i]!=s[j]，当前边界不可扩展，下一待尝试的边界长j=b[j]，因为较短边界是较长边界的边界
        string sReverse(s.rbegin(), s.rend());
        string ss = s + '\0' + sReverse;
        
        const int N = (int)ss.size();
        vector<int> b(N + 1, 0);
        int i = 0;
        int j = -1;
        b[i] = j;
        while (i < N) {
            while (j >= 0 && ss[i] != ss[j]) j = b[j];
            ++i;
            ++j;
            b[i] = j;
        }
        
        auto prepend = sReverse.substr(0, s.size() - b[N]);
        return prepend + s;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.shortestPalindrome("ba");
    
    return 0;
}
