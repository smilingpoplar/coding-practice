//
//  construct-binary-tree-from-preorder-and-inorder-traversal
//  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//
//  Created by smilingpoplar on 15/6/16.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp; // val => idx
        for (int i = 0; i < inorder.size(); i++) 
            mp[inorder[i]] = i;
        return buildTree(preorder, inorder, 0, 0, preorder.size(), mp);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pi, int ii,
                        int len, unordered_map<int, int> &mp) {
        if (len <= 0) return NULL;
        int val = preorder[pi];
        auto root = new TreeNode(val);
        int leftLen = mp[val] - ii, rightLen = len - 1 - leftLen;
        root->left = buildTree(preorder, inorder, pi + 1, ii, leftLen, mp);
        root->right = buildTree(preorder, inorder, pi + 1 + leftLen, ii + leftLen + 1, rightLen, mp);
        return root;
    }
};

void print(TreeNode *root) {
    if (!root) return;
    print(root->left);
    print(root->right);
    cout << root->val << " ";
}

int main(int argc, const char * argv[]) {
    vector<int> preorder = {4,2,1,3,5};
    vector<int> inorder = {1,2,3,4,5};
    Solution solution;
    auto root = solution.buildTree(preorder, inorder);
    print(root); // 1 3 2 5 4
    
    return 0;
}
