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
        vector<string> result;
        vector<string> values;
        dfs(root, values, result);
        return result;
    }
private:
    void dfs(TreeNode *root, vector<string> &values, vector<string> &result) {
        if (!root) return;
        values.push_back(to_string(root->val));
        if (!root->left && !root->right) {
            string path;
            for (int i = 0; i < values.size(); i++) {
                if (i > 0) path += "->";
                path += values[i];
            }
            result.push_back(path);
        } else {
            dfs(root->left, values, result);
            dfs(root->right, values, result);
        }
        values.pop_back();
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
    auto result = solution.binaryTreePaths(&t);
    for (auto path : result) {
        cout << path << " ";
    }
    
    return 0;
}
