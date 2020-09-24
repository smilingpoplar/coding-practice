//
//  maximum-binary-tree-ii
//  https://leetcode.com/problems/maximum-binary-tree-ii/
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // 在笛卡尔树对应的数组右端添一个val，
        // 如果val不是最大值，val位置在root->val位置右侧，一定在root右子树中；
        // 如果val是最大值，前面数组值都在它的左子树中
        if (root && val < root->val) {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        } 
        auto node = new TreeNode(val);
        node->left = root;
        return node;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
