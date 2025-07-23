//
//  lowest-common-ancestor-of-a-binary-tree
//  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 在子树中找p或q，找到一个就返回
        if (!root || root == p || root == q) return root;

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;  // p和q分别在左右子树，root就是lca
        return left ? left : right;      // p和q都在某个子树
    }
};

int main(int argc, const char *argv[]) {
    TreeNode t(3);
    TreeNode t0(5);
    t.left = &t0;
    TreeNode t1(1);
    t.right = &t1;
    TreeNode t00(6);
    t0.left = &t00;
    TreeNode t01(2);
    t0.right = &t01;
    TreeNode t010(7);
    t01.left = &t010;
    TreeNode t011(4);
    t01.right = &t011;

    Solution solution;
    auto ancestor = solution.lowestCommonAncestor(&t, &t00, &t011);
    cout << ancestor->val << endl;  // 5

    return 0;
}
