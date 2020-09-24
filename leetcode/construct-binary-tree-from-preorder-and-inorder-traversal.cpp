//
//  construct-binary-tree-from-preorder-and-inorder-traversal
//  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMp; // val => idx
        const int N = inorder.size();
        for (int i = 0; i < N; i++) inMp[inorder[i]] = i;
        
        return buildTree(N, preorder, 0, inorder, 0, inMp);
    }
    
    // preorder[pi, pi+N)、inorder[ii, ii+N) 
    TreeNode* buildTree(int N, vector<int>& preorder, int pi, 
                vector<int>& inorder, int ii, unordered_map<int, int> &inMp) {
        if (N <= 0) return NULL;
        int val = preorder[pi];
        auto root = new TreeNode(val);
        int leftN = inMp[val] - ii, rightN = N - 1 - leftN;
        root->left = buildTree(leftN, preorder, pi + 1, inorder, ii, inMp);
        root->right = buildTree(rightN, preorder, pi + 1 + leftN, inorder, ii + leftN + 1, inMp);
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
