//
//  count-univalue-subtrees
//  https://leetcode.com/problems/count-univalue-subtrees/
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
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        isUnivalue(root, ans);
        return ans;
    }
    
    bool isUnivalue(TreeNode *root, int &ans) {
        if (!root) return true;

        auto left = isUnivalue(root->left, ans);
        auto right = isUnivalue(root->right, ans);
        if (!left || (root->left && root->left->val != root->val)) return false;
        if (!right || (root->right && root->right->val != root->val)) return false;

        ans++;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
