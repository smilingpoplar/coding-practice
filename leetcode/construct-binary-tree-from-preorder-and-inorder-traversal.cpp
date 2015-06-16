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
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    TreeNode* buildTree(vector<int>::iterator poBegin, vector<int>::iterator poEnd,
                        vector<int>::iterator ioBegin, vector<int>::iterator ioEnd) {
        if (poBegin == poEnd || ioBegin == ioEnd) return NULL;
        auto root = new TreeNode(*poBegin);
        auto ioSplit = find(ioBegin, ioEnd, *poBegin);
        int leftSize = int(ioSplit - ioBegin);
        root->left = buildTree(poBegin + 1, poBegin + 1 + leftSize, ioBegin, ioSplit);
        root->right = buildTree(poBegin + 1 + leftSize, poEnd, ioSplit + 1, ioEnd);
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
