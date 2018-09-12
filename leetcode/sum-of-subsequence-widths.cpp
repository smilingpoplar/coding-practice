//
//  sum-of-subsequence-widths
//  https://leetcode.com/problems/sum-of-subsequence-widths/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        // 先排序，A[i]和A[j]间有(j-i-1)个数，每个数可选可不选构成子序列，
        // 以A[i]、A[j]为首位的子序列有2^(j-i-1)个，对ans贡献2^(j-i-1)*(A[j]-A[i])。
        // 另一角度看这式子，对任意A[i]，当它作为序列最小值时贡献-A[i]，作为序列最大值时贡献A[i]。
        // 而比A[i]大的数有N-1-i个，A[i]作为最小值的序列有2^(N-1-i)个，共对ans贡献2^(N-1-i)*(-A[i])；
        // 比A[i]小的数有i个，A[i]作为最大值的序列有2^i个，共对ans贡献2^i*A[i]；
        // 所以A[i]对ans贡献 A[i]*(2^i - 2^(N-1-i))
        // 1<=N<=20000，2^20000=10^6000，会溢出要取模
        sort(A.begin(), A.end());
        const int N = A.size(), MOD = 1e9 + 7;
        vector<int> pow2(N, 1);
        for (int i = 1; i < N; i++) {
            pow2[i] = (pow2[i-1] << 1) % MOD;
        }
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = (ans + (long)A[i] * (pow2[i] - pow2[N-1-i])) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
