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
        vector<int> ans;
        stack<TreeNode *> stk;
        auto curr = root; // curr是待入栈的节点
        TreeNode *prev = NULL;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            auto node = stk.top();
            if (node->right && node->right != prev) { // 不是从右子树返回，则先访问右子树
                curr = node->right;
            } else { // 从右子树返回，则出栈时访问
                stk.pop();
                ans.push_back(node->val);
                prev = node;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // morris后序遍历，对morris中序遍历作两处改动：
        // 1.添加dummy节点，dummy.left = root;
        // 2.访问完左子树后，倒序输出从左子树根节点current->left往右直到前驱节点prev这路径上的各个节点
        // 遍历过程同morris中序遍历，用中序遍历前驱节点的右指针prev->right表示左子树是否访问过
        // prev->right为空 => 左子树未访问过，记住要返回到当前节点，进入左子树
        // prev->right非空 => 左子树已访问过，清空prev->right，倒序输出从左子树根节点current->left往右直到前驱节点prev这路径上的各个节点，进入右子树
        TreeNode dummy(-1);
        dummy.left = root;
        auto current = &dummy;
        TreeNode *prev = NULL;
        vector<int> result;
        while (current) {
            if (!current->left) {
                current = current->right;
            } else {
                // 找到中序遍历前驱结点（左子树的最右节点）
                prev = current->left;
                while (prev->right && prev->right != current) {
                    prev = prev->right;
                }
                if (!prev->right) { // 左子树未访问过
                    prev->right = current;
                    current = current->left;
                } else { // 左子树已访问过
                    prev->right = NULL;
                    reverseVisit(current->left, prev, result);
                    current = current->right;
                }
            }
        }
        return result;
    }
private:
    void reverseVisit(TreeNode *from, TreeNode *to, vector<int> &result) {
        if (!from) return;
        reverseVisit(from->right, to, result);
        result.push_back(from->val);
    }
};
*/

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
