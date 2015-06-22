//
//  count-complete-tree-nodes
//  https://leetcode.com/problems/count-complete-tree-nodes/
//
//  Created by smilingpoplar on 15/6/20.
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
    /*
    // 递归
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight == rightHeight) { // 左子树是满二叉树
            return (1 << leftHeight) + countNodes(root->right);
        } else { // 右子树是满二叉树
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
    */
    // 迭代
    int countNodes(TreeNode* root) {
        int count = 0;
        while (root) {
            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->right);
            if (leftHeight == rightHeight) { // 左子树是满二叉树
                count += (1 << leftHeight);
                root = root->right;
            } else { // 右子树是满二叉树
                count += (1 << rightHeight);
                root = root->left;
            }
        }
        return count;
    }
private:
    int getHeight(TreeNode *root) {
        int height = 0;
        while (root) {
            root = root->left;
            ++height;
        }
        return height;
    }
};

int main(int argc, const char * argv[]) {
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
