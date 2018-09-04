//
//  same-tree
//  https://leetcode.com/problems/same-tree/
//
//  Created by smilingpoplar on 15/5/22.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode p0(3);
    TreeNode p1l(1);
    p0.left = &p1l;
    TreeNode p2r(2);
    p1l.right = &p2r;
    
    TreeNode q0(3);
    TreeNode q1l(1);
    q0.left = &q1l;
    TreeNode q2r(2);
    q1l.right = &q2r;
    
    Solution solution;
    cout << solution.isSameTree(&p0, &q0);
    
    return 0;
}
