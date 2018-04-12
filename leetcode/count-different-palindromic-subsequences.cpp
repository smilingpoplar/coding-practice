//
//  count-different-palindromic-subsequences
//  https://leetcode.com/problems/count-different-palindromic-subsequences/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int charCnt = 4;
    const int MOD = 1e9 + 7;
public:
    int countPalindromicSubsequences(string S) {
        // 比如"bccb"，先考虑所有相同字母x的最外层：比如对于x=b，考虑S[firstIdx(b)..lastIdx(b)]，
        // 这最外层可贡献回文b、bb（firstIdx(b)!=lastIdx(b)时）；然后对于bb，剥去最外层可得到子问题：
        // S[firstIdx(b)+1..lastIdx(b)-1]]。不同字母x的子问题不重叠，count可相加。
        const int N = S.size();
        vector<set<int>> idx(charCnt);
        for (int i = 0; i < N; i++) {
            idx[S[i] - 'a'].insert(i);
        }

        vector<vector<int>> memo(N, vector<int>(N, -1));
        return rCount(0, N - 1, idx, memo);
    }
    
    int rCount(int start, int end, vector<set<int>> &idx, vector<vector<int>> &memo) {
        if (start > end) return 0;
        if (memo[start][end] != -1) return memo[start][end];
        
        long ans = 0;
        for (int x = 0; x < charCnt; x++) {
            auto itStart = idx[x].lower_bound(start);
            if (itStart == idx[x].end() || *itStart > end) continue;
            auto itEnd = idx[x].upper_bound(end); itEnd--; // idx[x]非空，可itEnd--
            ans += (*itStart == *itEnd) ? 1 : 2; // 最外层贡献c、cc
            ans += rCount(*itStart + 1, *itEnd - 1, idx, memo) % MOD; // 最外层cc、拼接上内层：c..c
        }
        memo[start][end] = ans % MOD;
        return memo[start][end];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
