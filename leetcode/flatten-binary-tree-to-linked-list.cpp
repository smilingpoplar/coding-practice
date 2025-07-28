//
//  flatten-binary-tree-to-linked-list
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *prev = nullptr;
        preorder(root, prev);
    }

    void preorder(TreeNode *root, TreeNode *&prev) {
        if (!root) return;
        auto left = root->left, right = root->right;
        root->left = root->right = nullptr;
        if (prev) prev->right = root;
        prev = root;

        if (left) preorder(left, prev);
        if (right) preorder(right, prev);
    }
};

int main(int argc, const char *argv[]) {
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
