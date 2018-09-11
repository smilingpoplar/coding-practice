//
//  validate-binary-search-tree
//  https://leetcode.com/problems/validate-binary-search-tree/
//
//  Created by smilingpoplar on 15/5/23.
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode *root, long lower, long upper) {
        if (!root) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 确保bst的中序遍历单调递增
        auto curr = root;
        stack<TreeNode *> stk;
        TreeNode *prev = NULL;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            } 
            auto node = stk.top(); stk.pop();                
            if (prev && prev->val >= node->val) return false;
            prev = node;
            curr = node->right;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t2r(2);
    t1l.right = &t2r;
    
    Solution solution;
    cout << solution.isValidBST(&t0);
    
    return 0;
}
