//
//  balanced-binary-tree
//  https://leetcode.com/problems/balanced-binary-tree/
//
//  Created by smilingpoplar on 15/8/21.
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
    bool isBalanced(TreeNode *root) {
        return getHeight(root) >= 0;
    }

    // 返回树的高度（balanced）或返回-1（non-balanced）
    int getHeight(TreeNode *root) {
        if (!root) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t(1);
    TreeNode t0(2);
    t.left = &t0;
    TreeNode t1(3);
    t.right = &t1;
    TreeNode t01(4);
    t0.right = &t01;
    
    Solution solution;
    cout << solution.isBalanced(&t);
    
    return 0;
}
