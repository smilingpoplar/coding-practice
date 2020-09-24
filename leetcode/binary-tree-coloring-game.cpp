//
//  binary-tree-coloring-game
//  https://leetcode.com/problems/binary-tree-coloring-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // x将树分成3部分：左子树、右子树、与父节点相连的其余部分
        // 后手只要占据三者中最大一个的入口就能赢
        int L = 0, R = 0;
        count(root, x, L, R);
        int mx = max({L, R, n - 1 - L - R});
        return mx >= (n + 1) / 2;
    }
    
    int count(TreeNode *root, int x, int &L, int &R) {
        if (!root) return 0;
        int left = count(root->left, x, L, R);
        int right = count(root->right, x, L, R);
        if (root->val == x) {
            L = left, R = right;
        }
        return 1 + left + right;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
