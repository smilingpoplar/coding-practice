//
//  invert-binary-tree
//  https://leetcode.com/problems/invert-binary-tree/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};
*/

#include <vector>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 使用栈的通用图遍历算法就是dfs中的先序遍历
        vector<TreeNode *> stack;
        if (root) stack.push_back(root);
        while (!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            swap(node->left, node->right);
            
            if (node->left) stack.push_back(node->left);
            if (node->right) stack.push_back(node->right);
        }
        return root;
    }
};

void print(TreeNode *root) {
    if (!root) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main(int argc, const char * argv[]) {
    TreeNode t0(1);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t1r(3);
    t0.right = &t1r;
    TreeNode t2l(4);
    t1l.left = &t2l;
    TreeNode t2r(5);
    t1l.right = &t2r;
    
    Solution solution;
    auto root = solution.invertTree(&t0);
    print(root); // 1 3 2 5 4
 
    return 0;
}