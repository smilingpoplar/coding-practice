//
//  maximal-square
//  https://leetcode.com/problems/maximal-square/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int idx = 0;
        return bstFromPreorder(A, idx, INT_MAX);
    }
    
    TreeNode* bstFromPreorder(vector<int>& A, int &idx, int upperBound) {
        if (idx >= A.size() || A[idx] > upperBound) return NULL;

        int val = A[idx++];
        auto node = new TreeNode(val);
        node->left = bstFromPreorder(A, idx, val);
        node->right = bstFromPreorder(A, idx, upperBound);
        return node;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
