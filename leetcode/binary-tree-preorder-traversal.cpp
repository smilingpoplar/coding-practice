//
//  binary-tree-preorder-traversal
//  https://leetcode.com/problems/binary-tree-preorder-traversal/
//
//  Created by smilingpoplar on 15/5/13.
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

/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // 使用栈的通用图遍历算法就是dfs中的先序遍历
        vector<int> result;
        vector<TreeNode *> stack;
        if (root) stack.push_back(root);
        while (!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            if (node->right) stack.push_back(node->right);
            if (node->left) stack.push_back(node->left);
        }
        return result;
    }
};
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // morris前序遍历，只是把morris中序遍历里访问当前节点的语句换个位置
        // 用当前节点的中序遍历前驱节点的右指针prev->righ表示左子树是否访问过
        // prev->right为空 => 左子树未访问过，访问当前节点，记住要返回到当前节点，进入左子树
        // prev->right非空 => 左子树已访问过，清空prev->right，进入右子树
        vector<int> result;
        auto current = root;
        TreeNode *prev = NULL;
        while (current) {
            if (!current->left) {
                result.push_back(current->val);
                current = current->right;
            } else {
                // 找到前驱结点（左子树的最右节点）
                prev = current->left;
                while (prev->right && prev->right != current) {
                    prev = prev->right;
                }
                if (!prev->right) { // 左子树未访问过
                    result.push_back(current->val); // 把这句话放到这里
                    prev->right = current;
                    current = current->left;
                } else { // 左子树已访问过
                    prev->right = NULL;
                    current = current->right;
                }
            }
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
    auto result = solution.preorderTraversal(&t0);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
