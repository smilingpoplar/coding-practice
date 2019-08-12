//
//  smallest-string-starting-from-leaf
//  https://leetcode.com/problems/smallest-string-starting-from-leaf/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        // 后面的min(subtree,NULL)比较不能选空子树，所以要让空子树返回很大值
        if (!root) return string(1, 'a' + 26);
        
        string s(1, 'a' + root->val);
        if (!root->left && !root->right) return s;
        return min(smallestFromLeaf(root->left) + s, smallestFromLeaf(root->right) + s);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
