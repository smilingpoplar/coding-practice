//
//  number-of-subsequences-that-satisfy-the-given-sum-condition
//  https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& A, int target) {
        // 子序列的最大最小值与顺序无关，排序数组
        sort(A.begin(), A.end());
        // 预先计算pow2[]
        const int N = A.size(), MOD = 1e9 + 7;
        vector<int> pow2(N);
        pow2[0] = 1;
        for (int i = 1; i < N; i++) {
            pow2[i] = (pow2[i-1] << 1) % MOD;
        }
        // 对A[i]，找A[i]+A[j]<=target的最大j，两指针法
        int ans = 0;
        for (int i = 0, j = N - 1; i <= j; ) {
            if (A[i] + A[j] > target) {
                j--;
            } else {
                // 非空子序列，选了A[i]后，(i..j]间的数可选或不选，有2^(j-i)种可能
                ans = (ans + pow2[j-i]) % MOD;
                i++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
