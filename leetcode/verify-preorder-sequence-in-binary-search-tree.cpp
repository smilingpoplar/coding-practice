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
    
    // 用(lower, upper)值边界判断A[sIdx..eIdx)
    bool verify(vector<int> &A, int sIdx, int eIdx, int lower, int upper) {
        if (sIdx >= eIdx) return true;
        int rootVal = A[sIdx];
        if (rootVal <= lower || rootVal >= upper) return false;
        int i = sIdx + 1;
        while (i < eIdx && A[i] < rootVal) i++;
        if (!verify(A, sIdx + 1, i, lower, rootVal)) return false;
        if (!verify(A, i, eIdx, rootVal, upper)) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
