//
//  count-different-palindromic-subsequences
//  https://leetcode.com/problems/count-different-palindromic-subsequences/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int CHAR_CNT = 4; // 只有abcd四种字母
    const int MOD = 1e9 + 7;
public:
    int countPalindromicSubsequences(string S) {
        // 考虑某字母作最外层的区间，比如"bccb"，b作最外层的区间S[firstIdx(b)..lastIdx(b)]。
        // 这最外层可贡献回文b（不再考虑内层）、bb（firstIdx(b)!=lastIdx(b)）。
        // 当最外层为bb时，内层可为空集和非空子问题S[firstIdx(b)+1..lastIdx(b)-1]]。
        // 只要最外层不同就一定是不同的回文串，不用管内层是什么，计数可累加。
        const int N = S.size();
        vector<set<int>> idxSets(CHAR_CNT); // char=>idxSet
        for (int i = 0; i < N; i++) {
            idxSets[S[i] - 'a'].insert(i);
        }

        vector<vector<int>> memo(N, vector<int>(N, -1)); // S[lo..hi] => count
        return dfs(0, N - 1, idxSets, memo);
    }
    
    int dfs(int lo, int hi, vector<set<int>> &idxSets, vector<vector<int>> &memo) {
        if (lo > hi) return 0;
        if (memo[lo][hi] != -1) return memo[lo][hi];
        
        long ans = 0;
        for (int i = 0; i < CHAR_CNT; i++) {
            auto itLo = idxSets[i].lower_bound(lo);
            if (itLo == idxSets[i].end() || *itLo > hi) continue;
            auto itHi = idxSets[i].upper_bound(hi); 
            itHi--; // *itLo<=hi，<=hi非空，可itHi--
            ans += (*itLo == *itHi) ? 1 : 2; // 最外层贡献c、cc
            ans += dfs(*itLo + 1, *itHi - 1, idxSets, memo); // 剥掉最外层c..c、内层子问题
        }
        memo[lo][hi] = ans % MOD;
        return memo[lo][hi];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
