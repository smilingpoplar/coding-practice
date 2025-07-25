//
//  count-complete-tree-nodes
//  https://leetcode.com/problems/count-complete-tree-nodes/
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
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        if (leftH == rightH) {  // 左子树是满二叉树，左子树和根节点共(2^leftH-1)+1
            return (1 << leftH) + countNodes(root->right);
        } else {  // 右子树是满二叉树
            return (1 << rightH) + countNodes(root->left);
        }
    }

    int getHeight(TreeNode *root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }
};

int main(int argc, const char *argv[]) {
    TreeNode t0(0);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t1r(2);
    t0.right = &t1r;
    TreeNode t2l(3);
    t1l.left = &t2l;

    Solution solution;
    cout << solution.countNodes(&t0);

    return 0;
}
