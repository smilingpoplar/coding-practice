//
//  flip-binary-tree-to-match-preorder-traversal
//  https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        // 类似表达式解析问题，有个idx记录解析位置
        int idx = 0;
        vector<int> ans;
        if (match(root, voyage, idx, ans)) return ans;
        return {-1};
    }
    
    bool match(TreeNode* root, vector<int>& voyage, int &idx, vector<int> &ans) {
        if (!root) return true;
        if (root->val != voyage[idx++]) return false;
        if (root->left && root->left->val != voyage[idx]) {
            ans.push_back(root->val); // flip
            return match(root->right, voyage, idx, ans) 
                && match(root->left, voyage, idx, ans);
        }
        return match(root->left, voyage, idx, ans) 
            && match(root->right, voyage, idx, ans);            
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
