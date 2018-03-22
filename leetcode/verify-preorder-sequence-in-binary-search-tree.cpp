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
        // 用上下值边界(lower, upper)判断
        return check(preorder, 0, preorder.size(), INT_MIN, INT_MAX);
    }
    
    bool check(vector<int> &vec, int startIdx, int endIdx, int lower, int upper) {
        if (startIdx >= endIdx) return true;
        int rootVal = vec[startIdx];
        if (rootVal <= lower || rootVal >= upper) return false;
        int i = startIdx + 1;
        while (i < endIdx && vec[i] < rootVal) i++;
        if (!check(vec, startIdx + 1, i, lower, rootVal)) return false;
        if (!check(vec, i, endIdx, rootVal, upper)) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
