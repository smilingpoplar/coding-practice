//
//  squares-of-a-sorted-array
//  https://leetcode.com/problems/squares-of-a-sorted-array/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int N = A.size();
        vector<int> ans(N);
        int i = 0, j = N -1;
        for (int k = N - 1; k >= 0; k--) {
            if (abs(A[i]) > abs(A[j])) {
                ans[k] = A[i] * A[i];
                i++;
            } else {
                ans[k] = A[j] * A[j];
                j--;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}