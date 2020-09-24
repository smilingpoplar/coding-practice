//
//  count-different-palindromic-subsequences
//  https://leetcode.com/problems/count-different-palindromic-subsequences/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int CHAR_CNT = 4; // 只有abcd四种字母
    const int MOD = 1e9 + 7;
public:
    int countPalindromicSubsequences(string S) {
        // 先考虑某字母的最外层区间。比如"bccb"，先考虑b的最外层区间S[firstIdx(b)..lastIdx(b)]。
        // 这最外层可贡献回文b（不再考虑内层）、bb（firstIdx(b)!=lastIdx(b)），剥去最外层的bb，
        // 还可得内层子问题：S[firstIdx(b)+1..lastIdx(b)-1]]。
        // 不同字母的子问题不重叠，count可相加。
        const int N = S.size();
        vector<set<int>> idxSet(CHAR_CNT); // char => index_set
        for (int i = 0; i < N; i++) {
            idxSet[S[i] - 'a'].insert(i);
        }

        vector<vector<int>> memo(N, vector<int>(N, -1)); // S[lo..hi] => count
        return rCount(0, N - 1, idxSet, memo);
    }
    
    int rCount(int lo, int hi, vector<set<int>> &idxSet, vector<vector<int>> &memo) {
        if (lo > hi) return 0;
        if (memo[lo][hi] != -1) return memo[lo][hi];
        
        long ans = 0;
        for (int i = 0; i < CHAR_CNT; i++) {
            auto itLo = idxSet[i].lower_bound(lo);
            if (itLo == idxSet[i].end() || *itLo > hi) continue;
            auto itHi = idxSet[i].upper_bound(hi); 
            itHi--; // *itLo<=hi，<=hi非空，可itHi--
            ans += (*itLo == *itHi) ? 1 : 2; // 最外层贡献c、cc
            ans += rCount(*itLo + 1, *itHi - 1, idxSet, memo); // 剥掉最外层c..c、内层子问题
        }
        memo[lo][hi] = ans % MOD;
        return memo[lo][hi];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
