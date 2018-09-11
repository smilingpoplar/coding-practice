//
//  verify-preorder-sequence-in-binary-search-tree
//  https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verify(preorder, 0, preorder.size(), INT_MIN, INT_MAX);
    }
    
    // 用值区间(lower,upper)判断A[start..end)
    bool verify(vector<int> &A, int start, int end, int lower, int upper) {
        if (start >= end) return true;
        int val = A[start];
        if (val <= lower || val >= upper) return false;
        int i = start + 1;
        while (i < end && A[i] < val) i++;
        if (!verify(A, start + 1, i, lower, val)) return false;
        if (!verify(A, i, end, val, upper)) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
