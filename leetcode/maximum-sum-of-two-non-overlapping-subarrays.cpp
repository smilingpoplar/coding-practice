//
//  maximum-sum-of-two-non-overlapping-subarrays
//  https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // 题目：两个不重叠子段，L在M前或M在L前
        const int N = A.size();
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + A[i];
        }
        
        int Lmax = 0, Mmax = 0, ans = 0;
        for (int i = L + M; i <= N; i++) {
            // L在M前
            Lmax = max(Lmax, presum[i-M] - presum[i-L-M]);
            ans = max(ans, Lmax + (presum[i] - presum[i-M]));
            // M在L前
            Mmax = max(Mmax, presum[i-L] - presum[i-L-M]);
            ans = max(ans, Mmax + (presum[i] - presum[i-L]));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
