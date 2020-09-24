//
//  delete-leaves-with-a-given-value
//  https://leetcode.com/problems/delete-leaves-with-a-given-value/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (!root->left && !root->right && root->val == target) return nullptr;
        return root;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
