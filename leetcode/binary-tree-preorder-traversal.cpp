//
//  binary-tree-preorder-traversal
//  https://leetcode.com/problems/binary-tree-preorder-traversal/
//
//  Created by smilingpoplar on 15/5/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // 使用栈的通用图遍历算法就是dfs中的先序遍历
        vector<int> result;
        vector<TreeNode *> stack;
        if (root) stack.push_back(root);
        while (!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            if (node->right) stack.push_back(node->right);
            if (node->left) stack.push_back(node->left);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(9);
    t0.left = &t1l;
    TreeNode t1r(20);
    t0.right = &t1r;
    TreeNode t2l(15);
    t1r.left = &t2l;
    TreeNode t2r(7);
    t1r.right = &t2r;
    
    Solution solution;
    auto result = solution.preorderTraversal(&t0);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
