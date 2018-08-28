//
//  construct-binary-tree-from-inorder-and-postorder-traversal
//  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp; // val => idx
        for (int i = 0; i < inorder.size(); i++) 
            mp[inorder[i]] = i;
        return buildTree(inorder, postorder, 0, 0, inorder.size(), mp);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int ii, int pi,
                        int len, unordered_map<int, int> &mp) {
        if (len <= 0) return NULL;
        int val = postorder[pi + len - 1];
        auto root = new TreeNode(val);
        int leftLen = mp[val] - ii, rightLen = len - 1 - leftLen;
        root->left = buildTree(inorder, postorder, ii, pi, leftLen, mp);
        root->right = buildTree(inorder, postorder, ii + leftLen + 1, pi + leftLen, rightLen, mp);
        return root;
    }
};

void print(TreeNode *root) {
    if (!root) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main(int argc, const char * argv[]) {
    vector<int> inorder = {1,2,3,4,5};
    vector<int> postorder = {1,3,2,5,4};
    Solution solution;
    auto root = solution.buildTree(inorder, postorder);
    print(root); // 4 2 1 3 5
    
    return 0;
}
