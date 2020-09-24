//
//  count-good-nodes-in-binary-tree
//  https://leetcode.com/problems/count-good-nodes-in-binary-tree/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0, mx = INT_MIN;
        dfs(root, mx, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int mx, int &ans) {
        if (!root) return;
        if (mx <= root->val) ans++;
        mx = max(mx, root->val);
        dfs(root->left, mx, ans);
        dfs(root->right, mx, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
