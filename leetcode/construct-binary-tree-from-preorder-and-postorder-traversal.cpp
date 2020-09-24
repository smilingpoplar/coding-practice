//
//  construct-binary-tree-from-preorder-and-postorder-traversal
//  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
//
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> preMp; // val => idx
        const int N = pre.size();
        for (int i = 0; i < N; i++) preMp[pre[i]] = i;
        
        return buildTree(N, pre, 0, post, 0, preMp);
    }
    
    // pre[preI, preI+N)、post[postI, postI+N)
    TreeNode* buildTree(int N, vector<int>& pre, int preI, 
                vector<int>& post, int postI, unordered_map<int, int> &preMp) {
        if (N <= 0) return NULL;
        auto root = new TreeNode(pre[preI]);
        if (N == 1) return root;
        int rightRootVal = post[postI + N - 2];
        int leftN = preMp[rightRootVal] - (preI + 1), rightN = N - 1 - leftN;
        root->left = buildTree(leftN, pre, preI + 1, post, postI, preMp);
        root->right = buildTree(rightN, pre, preI + 1 + leftN, post, postI + leftN, preMp);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
