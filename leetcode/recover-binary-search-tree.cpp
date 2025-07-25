//
//  recover-binary-search-tree
//  https://leetcode.com/problems/recover-binary-search-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    void recoverTree(TreeNode *root) {
        // 中序遍历，O(N)
        // 找出违反递增关系的最初prev节点、最后node节点
        stack<TreeNode *> stk;
        pushLeft(stk, root);

        TreeNode *prev = nullptr, *m1 = nullptr, *m2 = nullptr;
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if (prev && node->val <= prev->val) {
                if (!m1) m1 = prev;
                m2 = node;
            }
            prev = node;
            pushLeft(stk, node->right);
        }

        if (m1 && m2) swap(m1->val, m2->val);
    }

    void pushLeft(stack<TreeNode *> &stk, TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
};

/*
class Solution {
public:
    void recoverTree(TreeNode* root) {
        // 在遍历过程中，找出违反递增关系的首尾节点
        TreeNode *prev = NULL, *m1 = NULL, *m2 = NULL;
        // morris中序遍历，O(1)空间
        // 用中序遍历前驱节点的右指针pred->right表示左子树是否访问过
        // pred->right==NULL => 左子树未访问，记住要返回到当前节点，进入左子树
        // pred->right!=NULL => 左子树已访问，清空pred->right，访问当前节点，进入右子树
        auto curr = root;
        TreeNode *pred = NULL; // 中序遍历前驱节点
        while (curr) {
            if (!curr->left) {
                // 访问当前节点
                if (prev && curr->val < prev->val) {
                    if (!m1) m1 = prev;
                    m2 = curr;
                }
                prev = curr;
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
                    // 访问当前节点
                    if (prev && curr->val < prev->val) {
                        if (!m1) m1 = prev;
                        m2 = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (m1 && m2) swap(m1->val, m2->val);
    }
};
*/

void print(TreeNode *root) {
    if (!root) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main(int argc, const char *argv[]) {
    TreeNode t0(3);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t2r(1);
    t1l.right = &t2r;

    Solution solution;
    solution.recoverTree(&t0);
    print(&t0);  // 3 1 2

    return 0;
}
