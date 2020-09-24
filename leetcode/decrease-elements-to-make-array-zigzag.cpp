//
//  decrease-elements-to-make-array-zigzag
//  https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& A) {
        // 让even项或者odd项：A[i-1] > A[i] < A[i+1]
        const int N = A.size();
        vector<int> ans(2);
        for (int i = 0; i < N; i++) {
            int left = i - 1 >= 0 ? A[i-1] : INT_MAX;
            int right = i + 1 < N ? A[i+1] : INT_MAX;
            ans[i % 2] += max(0, A[i] - min(left, right) + 1);
        }
        return min(ans[0], ans[1]);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
