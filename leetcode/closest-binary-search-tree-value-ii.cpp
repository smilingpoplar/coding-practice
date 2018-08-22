//
//  closest-binary-search-tree-value-ii
//  https://leetcode.com/problems/closest-binary-search-tree-value-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
        // 前驱栈pre和后继栈succ
        stack<TreeNode *> pre, succ;
        auto p = root;
        while (p) {
            if (target < p->val) {
                succ.push(p);
                p = p->left;
            } else {
                pre.push(p);
                p = p->right;
            }
        }
        
        vector<int> ans;
        while (k--) {
            if (succ.empty() || (!pre.empty() && target - pre.top()->val < succ.top()->val - target)) { // 选前驱
                ans.push_back(pre.top()->val);
                getPredecessor(pre);
            } else {
                ans.push_back(succ.top()->val);
                getSuccessor(succ);
            }
        }
        return ans;
    }
    
    // 类似i--
    void getPredecessor(stack<TreeNode *> &pre) {
        auto top = pre.top(); pre.pop();
        auto p = top->left;
        while (p) {
            pre.push(p);
            p = p->right;
        }
    }
    
    // 类似j++
    void getSuccessor(stack<TreeNode *> &succ) {
        auto top = succ.top(); succ.pop();
        auto p = top->right;
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
        queue<int> q;
        inorder(root, target, k, q);
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    
    void inorder(TreeNode *root, double target, int k, queue<int> &q) {
        if (!root) return;
        // 中序遍历，相当于有序数组，找最接近target的k个数，维持一个k长的窗口。
        // 窗口右端指向大的数、左端指向小的数，每次从两端选一个更接近target的。
        inorder(root->left, target, k, q);
        if (q.size() < k) {
            q.push(root->val);
        } else if (abs(root->val - target) < abs(q.front() - target)) {
                q.pop();
                q.push(root->val);
        } else return;
        inorder(root->right, target, k, q);
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
