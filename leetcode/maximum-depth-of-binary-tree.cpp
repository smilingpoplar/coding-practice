//
//  maximum-depth-of-binary-tree
//  https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(0);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t1r(1);
    t0.right = &t1r;
    TreeNode t2r(2);
    t1r.right = &t2r;
    
    Solution solution;
    cout << solution.maxDepth(&t0);

    return 0;
}
