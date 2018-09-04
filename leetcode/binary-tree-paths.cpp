//
//  binary-tree-paths
//  https://leetcode.com/problems/binary-tree-paths/
//
//  Created by smilingpoplar on 15/8/21.
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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        vector<int> path;
        dfs(root, path, ans);
        return ans;
    }

    void dfs(TreeNode *root, vector<int> &path, vector<string> &ans) {
        if (!root) return;

        path.push_back(root->val);
        if (!root->left && !root->right) {
            string s;
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) s += "->";
                s += to_string(path[i]);
            }
            ans.push_back(s);
        } else {
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t(1);
    TreeNode t0(2);
    t.left = &t0;
    TreeNode t1(3);
    t.right = &t1;
    TreeNode t01(5);
    t0.left = &t01;
    
    Solution solution;
    auto ans = solution.binaryTreePaths(&t);
    for (auto path : ans) {
        cout << path << " ";
    }
    
    return 0;
}
