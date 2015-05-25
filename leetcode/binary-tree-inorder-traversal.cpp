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

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 中序遍历，用栈模拟，用curr表示调用栈[curr,stack]的栈顶
        vector<int> result;
        auto curr = root;
        vector<TreeNode *> stack;
        while (curr || !stack.empty()) {
            if (curr) { // 首先访问左子节点
                stack.push_back(curr);
                curr = curr->left;
            } else { // 当curr为空时从栈中取节点访问
                curr = stack.back();
                stack.pop_back();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return result;
    }
};
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // morris中序遍历，用当前节点的中序遍历前驱节点的右指针prev->right表示左子树是否访问过
        // prev->right为空 => 左子树未访问过，记住要返回到当前节点，进入左子树
        // prev->right非空 => 左子树已访问过，清空prev->right，访问当前节点，进入右子树
        vector<int> result;
        auto current = root;
        TreeNode *prev = NULL;
        while (current) {
            if (!current->left) {
                result.push_back(current->val); // 访问当前节点
                current = current->right;
            } else {
                // 找到中序遍历的前驱节点（左子树的最右节点）
                prev = current->left;
                while (prev->right && prev->right != current) {
                    prev = prev->right;
                }
                if (!prev->right) { // 左子树未访问过
                    prev->right = current;
                    current = current->left;
                } else { // 左子树已访问过
                    prev->right = NULL;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};

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
