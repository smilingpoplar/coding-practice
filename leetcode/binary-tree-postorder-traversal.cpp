//
//  binary-tree-postorder-traversal
//  https://leetcode.com/problems/binary-tree-postorder-traversal/
//
//  Created by smilingpoplar on 15/5/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // 后序遍历迭代版，用栈模拟，通过比较prev和curr来判断遍历方向
        vector<int> result;
        vector<TreeNode *> stack;
        if (root) stack.push_back(root);
        TreeNode *prev = NULL;
        while (!stack.empty()) {
            auto curr = stack.back();
            if (!prev || prev->left == curr || prev->right == curr) { // 正向下遍历
                if (curr->left) stack.push_back(curr->left);
                else if (curr->right) stack.push_back(curr->right);
                else {
                    result.push_back(curr->val);
                    stack.pop_back();
                }
            } else if (prev == curr->left) { // 从左子树返回
                if (curr->right) stack.push_back(curr->right);
                else {
                    result.push_back(curr->val);
                    stack.pop_back();
                }
            } else if (prev == curr->right) { // 从右子树返回
                result.push_back(curr->val);
                stack.pop_back();
            }
            prev = curr;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(9);
    t0.left = &t1l;
    TreeNode t1r(20);
    t0.right = &t1r;
    TreeNode t2l(15);
    t1r.left = &t2l;
    TreeNode t2r(7);
    t1r.right = &t2r;
    
    Solution solution;
    auto result = solution.postorderTraversal(&t0);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
