//
//  distinct-subsequences-ii
//  https://leetcode.com/problems/distinct-subsequences-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string S) {
        const int MOD = 1e9 + 7;
        vector<int> endsWith(26, 0); // 扫描到S[i]时、以各字母结尾的子序列数
        for (char c : S) {
            // 原先子序列都扩展个c，有sum(endsWith[])个；还有1个新的字母c序列
            // (不用担心旧的字母c序列，它被扩展成cc序列，和新的字母c序列不冲突)
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % MOD;
        }
        return accumulate(begin(endsWith), end(endsWith), 0L) % MOD;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
