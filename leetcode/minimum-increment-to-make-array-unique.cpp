//
//  minimum-increment-to-make-array-unique
//  https://leetcode.com/problems/minimum-increment-to-make-array-unique/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // 排序，然后保证A[i]>A[i-1]
        sort(A.begin(), A.end());
        const int N = A.size();
        int ans = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] <= A[i-1]) {
                ans += A[i-1] + 1 - A[i];
                A[i] = A[i-1] + 1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
