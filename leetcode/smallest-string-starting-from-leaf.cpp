//
//  smallest-string-starting-from-leaf
//  https://leetcode.com/problems/smallest-string-starting-from-leaf/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        // 注意，如果两串不等长，s1<s2不能推得s1+s<s2+s
        // 比如ab<abab，不能推得abz<ababz
        // dfs全部遍历
        string cur;
        string smallest(1, 'a' + 26);
        dfs(root, cur, smallest);
        return smallest;
    }
    
    void dfs(TreeNode *root, string cur, string &s) {
        if (!root) return;
        cur = char('a' + root->val) + cur;
        if (!root->left && !root->right) {
            s = min(s, cur);
            return;
        }
        dfs(root->left, cur, s);
        dfs(root->right, cur, s);        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
