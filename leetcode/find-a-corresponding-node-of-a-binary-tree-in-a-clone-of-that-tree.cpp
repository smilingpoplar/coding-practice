//
//  find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
//  https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || original == target) return cloned;
        auto ans = getTargetCopy(original->left, cloned->left, target);
        return ans ? ans : getTargetCopy(original->right, cloned->right, target);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
