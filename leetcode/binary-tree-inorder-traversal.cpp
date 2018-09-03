//
//  binary-tree-inorder-traversal
//  https://leetcode.com/problems/binary-tree-inorder-traversal/
//
//  Created by smilingpoplar on 15/5/18.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        auto curr = root; // curr表示当前待入栈的元素
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            } 
            auto node = stk.top();  stk.pop();
            ans.push_back(node->val);  // 出栈时访问
            curr = node->right;
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // morris中序遍历，用中序遍历前驱节点的右指针pred->right表示左子树是否已访问
        // pred->right==NULL => 左子树未访问，记住要返回到当前节点，进入左子树
        // pred->right!=NULL => 左子树已访问，清空pred->right，访问当前节点，进入右子树
        vector<int> ans;
        auto curr = root;
        TreeNode *pred = NULL;
        while (curr) {
            if (!curr->left) {
                ans.push_back(curr->val); // 访问当前节点
                curr = curr->right;
            } else {
                // 中序遍历的前驱节点（左子树的最右节点）
                pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                if (!pred->right) { // 左子树未访问
                    pred->right = curr;
                    curr = curr->left;
                } else { // 左子树已访问
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t2r(2);
    t1l.right = &t2r;
    
    Solution solution;
    auto result = solution.inorderTraversal(&t0);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
