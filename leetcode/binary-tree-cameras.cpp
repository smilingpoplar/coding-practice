//
//  binary-tree-cameras
//  https://leetcode.com/problems/binary-tree-cameras/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int NO_CAMERA_NOT_COVERED = 0;
    const int NO_CAMERA_BUT_COVERED = 1;
    const int CAMERA_HERE = 2;
public:
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if (dfs(root, ans) == NO_CAMERA_NOT_COVERED) ans++;
        return ans;
    }
    
    int dfs(TreeNode *root, int &ans) {
        if (!root) return NO_CAMERA_BUT_COVERED;
        int left = dfs(root->left, ans), right = dfs(root->right, ans);
        
        if (left == NO_CAMERA_NOT_COVERED || right == NO_CAMERA_NOT_COVERED) {
            ans++;
            return CAMERA_HERE;
        }
        if (left == CAMERA_HERE || right == CAMERA_HERE) {
            return NO_CAMERA_BUT_COVERED;
        }
        return NO_CAMERA_NOT_COVERED;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
