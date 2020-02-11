//
//  previous-permutation-with-one-swap
//  https://leetcode.com/problems/previous-permutation-with-one-swap/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        const int N = A.size();
        // 从右往左找第一个A[i]>A[i+1]
        int i = N - 2;
        while (i >= 0 && A[i] <= A[i+1]) i--;
        if (i < 0) return A;
        // 在A[i]右边找<A[i]的最大数，多个相同选最左的
        int rMax = INT_MIN, rMaxIdx;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[i] && A[j] > rMax) {
                rMax = A[j];
                rMaxIdx = j;
            }   
        }
        swap(A[i], A[rMaxIdx]);
        return A;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
