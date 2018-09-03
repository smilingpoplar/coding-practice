//
//  recover-binary-search-tree
//  https://leetcode.com/problems/recover-binary-search-tree/
//
//  Created by smilingpoplar on 15/5/29.
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
    void recoverTree(TreeNode* root) {
        // 中序遍历
        auto curr = root;
        stack<TreeNode *> stk;
        TreeNode *prev = NULL, *m1 = NULL, *m2 = NULL;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            // 找出违反递增关系的首尾节点
            auto node = stk.top(); stk.pop();
            if (prev && prev->val >= node->val) {
                if (!m1) m1 = prev;
                m2 = node;
            }
            prev = node;
            curr = node->right;
        }
        
        if (m1 && m2) swap(m1->val, m2->val);
    }
};
*/

class Solution {
public:
    void recoverTree(TreeNode* root) {
        // morris中序遍历，O(1)空间
        // 用当前节点的中序遍历前驱节点的右指针prev->right表示左子树是否访问过
        // prev->right为空 => 左子树未访问过，记住要返回到当前节点，进入左子树
        // prev->right非空 => 左子树已访问过，清空prev->right，访问当前节点，进入右子树
        // 在遍历过程中，找出违反递增趋势的第一个和最后一个节点
        TreeNode *firstSwapped = NULL;
        TreeNode *lastSwapped = NULL;
        TreeNode *lastVisited = NULL;
        
        auto current = root;
        TreeNode *prev = NULL;
        while (current) {
            if (!current->left) {
                // 访问当前节点
                if (lastVisited && current->val < lastVisited->val) {
                    if (!firstSwapped) firstSwapped = lastVisited;
                    lastSwapped = current;
                }
                lastVisited = current;
                current = current->right;
            } else {
                // 找出中序遍历的前驱节点（左子树的最右节点）
                prev = current->left;
                while (prev->right && prev->right != current) {
                    prev = prev->right;
                }
                if (!prev->right) { // 左子树未访问过
                    prev->right = current;
                    current = current->left;
                } else { // 左子树已访问过
                    prev->right = NULL;
                    // 访问当前节点
                    if (lastVisited && current->val < lastVisited->val) {
                        if (!firstSwapped) firstSwapped = lastVisited;
                        lastSwapped = current;
                    }
                    lastVisited = current;
                    current = current->right;
                }
            }
        }
        if (!firstSwapped || !lastSwapped) return;
        swap(firstSwapped->val, lastSwapped->val);
    }
};

void print(TreeNode *root) {
    if (!root) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t2r(1);
    t1l.right = &t2r;
    
    Solution solution;
    solution.recoverTree(&t0);
    print(&t0); // 3 1 2
    
    return 0;
}
