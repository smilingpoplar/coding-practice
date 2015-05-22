//
//  symmetric-tree
//  https://leetcode.com/problems/symmetric-tree/
//
//  Created by smilingpoplar on 15/5/22.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 递归版
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val
        && isSymmetric(left->left, right->right)
        && isSymmetric(left->right, right->left);
    }
};
*/

// 迭代版
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode *> queue;
        queue.push(root->left);
        queue.push(root->right);
        while (!queue.empty()) {
            auto left = queue.front();
            queue.pop();
            auto right = queue.front();
            queue.pop();
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            
            queue.push(left->left);
            queue.push(right->right);
            
            queue.push(left->right);
            queue.push(right->left);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(0);
    TreeNode t1l(1);
    TreeNode t1r(1);
    t0.left = &t1l;
    t0.right = &t1r;
    TreeNode t2ll(2);
    TreeNode t2lr(3);
    TreeNode t2rl(3);
    TreeNode t2rr(2);
    t1l.left = &t2ll;
    t1l.right = &t2lr;
    t1r.left = &t2rl;
    t1r.right = &t2rr;
    
    Solution solution;
    cout << solution.isSymmetric(&t0);
    
    return 0;
}
