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
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode* buildTree(vector<int>::iterator ioBegin, vector<int>::iterator ioEnd,
                        vector<int>::iterator poBegin, vector<int>::iterator poEnd) {
        if (ioBegin == ioEnd || poBegin == poEnd) return NULL;
        auto root = new TreeNode(*(poEnd - 1));
        auto ioSplit = find(ioBegin, ioEnd, *(poEnd - 1));
        int leftSize = int(ioSplit - ioBegin);
        root->left = buildTree(ioBegin, ioSplit, poBegin, poBegin + leftSize);
        root->right = buildTree(ioSplit + 1, ioEnd, poBegin + leftSize, poEnd - 1);
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
