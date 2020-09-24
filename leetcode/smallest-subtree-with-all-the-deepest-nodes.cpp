//
//  smallest-subtree-with-all-the-deepest-nodes
//  https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return getHeight(root).second;
    }
    
    // 返回：(height, substreeWithAllDeepest)
    pair<int, TreeNode*> getHeight(TreeNode *root) {
        if (!root) return {0, NULL};
        auto left = getHeight(root->left);
        auto right = getHeight(root->right);
        
        int h1 = left.first, h2 = right.first;
        if (h1 > h2) return {1 + h1, left.second};
        if (h1 < h2) return {1 + h2, right.second};
        return {1 + h1, root};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
