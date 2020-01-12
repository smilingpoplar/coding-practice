//
//  distinct-subsequences-ii
//  https://leetcode.com/problems/distinct-subsequences-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string S) {
        const int MOD = 1e9 + 7;
        // 用count[26]记录S[0..i]以各字母结尾的子序列各有多少
        vector<int> count(26, 0);
        long sum = 0; // sum为count[]的和
        for (char c : S) {
            // 以字母c结尾的子序列有sum+1个
            // sum为原先子序列扩展个c，1是新的字母c序列
            int idx = c - 'a';
            int diff = (sum + 1 - count[idx] + MOD) % MOD;
            count[idx] = (count[idx] + diff) % MOD;
            sum = (sum + diff) % MOD;
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
