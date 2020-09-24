//
//  sum-of-subsequence-widths
//  https://leetcode.com/problems/sum-of-subsequence-widths/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        // 子序列计算和，与顺序无关，排序数组
        // 比A[i]大的数有N-1-i个，A[i]作最小值的子序列有2^(N-1-i)个，A[i]对ans贡献2^(N-1-i)*(-A[i])
        // 比A[i]小的数有i个，A[i]作最大值的子序列有2^i个，对ans贡献2^i*A[i]
        // 所以，A[i]对ans贡献 A[i] * (2^i - 2^(N-1-i))
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
