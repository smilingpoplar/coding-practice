//
//  all-elements-in-two-binary-search-trees
//  https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;
        pushLeft(stk1, root1);
        pushLeft(stk2, root2);
        vector<int> ans;
        while (!stk1.empty() || !stk2.empty()) {
            auto &stk = stk1.empty() ? stk2 : 
                        (stk2.empty() ? stk1 : 
                        (stk1.top()->val <= stk2.top()->val ? stk1 : stk2));
            auto node = stk.top(); stk.pop();
            ans.push_back(node->val);
            pushLeft(stk, node->right);
        }
        return ans;
    }

    void pushLeft(stack<TreeNode*> &stk, TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
