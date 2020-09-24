//
//  lowest-common-ancestor-of-a-binary-search-tree
//  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 找值在p、q间的节点
        if (!root || !p || !q) return NULL;
        if (p->val > q->val) swap(p, q); // p.val < q.val
        while (root) {
            if (root->val < p->val) {
                root = root->right;
            } else if (root->val > q->val) {
                root = root->left;
            } else {
                break;
            }
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
    TreeNode t(1);
    TreeNode t0(1);
    t.left = &t0;
    TreeNode t00(1);
    t0.left = &t00;
    
    Solution solution;
    auto ancestor = solution.lowestCommonAncestor(&t, &t0, &t00);
    print(ancestor); // 1 1
    
    return 0;
}
