//
//  flatten-binary-tree-to-linked-list
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//
//  Created by smilingpoplar on 15/5/24.
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
    void flatten(TreeNode* root) {
        // 先序遍历
        vector<TreeNode *> stack;
        if (root) stack.push_back(root);
        TreeNode *prev = NULL;
        while (!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            if (node->right) stack.push_back(node->right);
            if (node->left) stack.push_back(node->left);
            
            node->left = node->right = NULL;
            if (prev) prev->right = node;
            prev = node;
        }
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(1);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t2r(3);
    t1l.right = &t2r;
    
    Solution solution;
    solution.flatten(&t0);
    auto head = &t0;
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
    
    return 0;
}
