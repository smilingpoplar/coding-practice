//
//  closest-binary-search-tree-value-ii
//  https://leetcode.com/problems/closest-binary-search-tree-value-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // 前驱栈pred和后继栈succ
        stack<TreeNode *> pred, succ;
        auto p = root;
        while (p) {
            if (target < p->val) {
                succ.push(p);
                p = p->left;
            } else {
                pred.push(p);
                p = p->right;
            }
        }
        
        vector<int> ans;
        while (k--) {
            // 往两端的两指针
            if (succ.empty() || (!pred.empty() && target - pred.top()->val < succ.top()->val - target)) { // 选前驱
                ans.push_back(pred.top()->val);
                getPredecessor(pred);
            } else {
                ans.push_back(succ.top()->val);
                getSuccessor(succ);
            }
        }
        return ans;
    }
    
    // 类似i--，到左子树最右儿子的路径
    void getPredecessor(stack<TreeNode *> &pred) {
        auto node = pred.top(); pred.pop();
        auto p = node->left;
        while (p) {
            pred.push(p);
            p = p->right;
        }
    }
    
    // 类似j++，到右子树最左儿子的路径
    void getSuccessor(stack<TreeNode *> &succ) {
        auto node = succ.top(); succ.pop();
        auto p = node->right;
        while (p) {
            succ.push(p);
            p = p->left;
        }
    }
};

/*
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> q;
        inorder(root, target, k, q);
        return vector<int>(q.begin(), q.end());
    }
    
    void inorder(TreeNode *root, double target, int k, deque<int> &q) {
        if (!root) return;
        // 用中序遍历和k长队列
        inorder(root->left, target, k, q);
        if (q.size() < k) {
            q.push_back(root->val);
        } else if (abs(root->val - target) < abs(q.front() - target)) {
            q.pop_front();
            q.push_back(root->val);
        } else return;
        inorder(root->right, target, k, q);
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
