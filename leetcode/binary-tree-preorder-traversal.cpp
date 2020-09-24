//
//  binary-tree-preorder-traversal
//  https://leetcode.com/problems/binary-tree-preorder-traversal/
//
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
        // 使用栈的图遍历
        vector<int> ans;
        stack<TreeNode *> stk;
        if (root) stk.push(root);
        while (!stk.empty()) {
            auto node = stk.top(); stk.pop();
            ans.push_back(node->val);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        auto curr = root; // curr是待入栈的节点
        while (curr || !stk.empty()) {
            while (curr) {
                ans.push_back(curr->val); // 进栈前访问
                stk.push(curr);
                curr = curr->left;
            }
            auto node = stk.top(); stk.pop();
            curr = node->right;
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // morris前序遍历，只是把morris中序遍历里访问当前节点的语句换个位置
        // 用中序遍历前驱节点的右指针pred->righ表示左子树是否已访问
        // pred->right==NULL => 左子树未访问，访问当前节点，记住要返回到当前节点，进入左子树
        // pred->right!=NULL => 左子树已访问，清空pred->right，进入右子树
        vector<int> ans;
        auto curr = root;
        TreeNode *pred = NULL;
        while (curr) {
            if (!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // 中序遍历前驱节点（左子树的最右节点）
                pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                if (!pred->right) { // 左子树未访问
                    ans.push_back(curr->val); // 把这句话放到这里
                    pred->right = curr;
                    curr = curr->left;
                } else { // 左子树已访问
                    pred->right = NULL;
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
