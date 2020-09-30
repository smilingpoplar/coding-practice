//
//  get-the-maximum-score
//  https://leetcode.com/problems/get-the-maximum-score/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& A, vector<int>& B) {
        // 数组有些公共元素，公共元素间的路径两数组各有一条，选大的那条
        const int MOD = 1e9 + 7;
        const int M = A.size(), N = B.size();
        int i = 0, j = 0;
        long sumA = 0, sumB = 0;
        while (i < M || j < N) {
            if (j == N || (i < M && A[i] < B[j])) {
                sumA += A[i++];
            } else if (i == M || (j < N && A[i] > B[j])) {
                sumB += B[j++];
            } else {
                sumA = sumB = max(sumA, sumB) + A[i];
                i++, j++;
            }
        }
        return max(sumA, sumB) % MOD;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
