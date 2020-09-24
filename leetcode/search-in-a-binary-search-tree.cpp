//
//  search-in-a-binary-search-tree
//  https://leetcode.com/problems/search-in-a-binary-search-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && val != root->val) {
            if (val < root->val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
