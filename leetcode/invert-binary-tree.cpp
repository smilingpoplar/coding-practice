//
//  invert-binary-tree
//  https://leetcode.com/problems/invert-binary-tree/
//
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
        auto left = invertTree(root->left), right = invertTree(root->right);
        root->left = right, root->right = left;
        return root;
    }
};
*/

#include <vector>

class Solution {
public:
        TreeNode* invertTree(TreeNode* root) {
            // 用栈的图遍历
            stack<TreeNode *> stk;
            if (root) stk.push(root);
            while (!stk.empty()) {
                auto node = stk.top(); stk.pop();
                swap(node->left, node->right);
                
                if (node->left) stk.push(node->left);
                if (node->right) stk.push(node->right);
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
