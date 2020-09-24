//
//  leaf-similar-trees
//  https://leetcode.com/problems/leaf-similar-trees/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        return leaves1 == leaves2;
    }
    
    void dfs(TreeNode *root, vector<int> &leaves) {
        if (!root) return;
        if (!root->left && !root->right) leaves.push_back(root->val);
        
        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
