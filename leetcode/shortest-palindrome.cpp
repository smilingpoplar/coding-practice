//
//  shortest-palindrome
//  https://leetcode.com/problems/shortest-palindrome/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        // 求s串首开始的最长回文长
        string r(s.rbegin(), s.rend());
        string S = s + "#" + r;
        // 变成求S前缀等于后缀的最大边界长
        // 用KMP算法的预处理，设b[i]表示长为i的前缀S[0..i-1]的最大边界长
        // 不变式：i是前缀长、j是边界长
        const int N = S.size();
        vector<int> b(N + 1);
        int i = 0, j = -1;
        b[i] = j;
        while (i < N) {
            // 尝试扩展到S[i]
            while (j >= 0 && S[i] != S[j]) // 无法扩展当前边界
                j = b[j]; // 尝试下一小的边界
            // 可以扩展了
            ++i; ++j;
            b[i] = j;
        }
        
        string prepend = r.substr(0, s.size() - b[N]);
        return prepend + s;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
