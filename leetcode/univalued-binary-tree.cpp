//
//  univalued-binary-tree
//  https://leetcode.com/problems/univalued-binary-tree/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        return isUnivalTree(root, root->val);
    }
    
    bool isUnivalTree(TreeNode* root, int val) {
        if (!root) return true;
        if (root->val != val) return false;
        return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
