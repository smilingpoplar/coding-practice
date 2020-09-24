//
//  construct-binary-tree-from-inorder-and-postorder-traversal
//  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMp; // val => idx
        const int N = inorder.size();
        for (int i = 0; i < N; i++)  inMp[inorder[i]] = i;

        return buildTree(N, inorder, 0, postorder, 0, inMp);
    }
    
    // inorder[ii, ii+N)、postorder[pi, pi+N)
    TreeNode* buildTree(int N, vector<int>& inorder, int ii, 
                    vector<int>& postorder, int pi, unordered_map<int, int> &inMp) {
        if (N <= 0) return NULL;
        int val = postorder[pi + N - 1];
        auto root = new TreeNode(val);
        int leftN = inMp[val] - ii, rightN = N - 1 - leftN;
        root->left = buildTree(leftN, inorder, ii, postorder, pi, inMp);
        root->right = buildTree(rightN, inorder, ii + leftN + 1, postorder, pi + leftN, inMp);
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
