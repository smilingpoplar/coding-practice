//
//  all-possible-full-binary-trees
//  https://leetcode.com/problems/all-possible-full-binary-trees/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        unordered_map<int, vector<TreeNode*>> memo;
        return dfs(N, memo);
    }
    
    vector<TreeNode*> dfs(int n, unordered_map<int, vector<TreeNode*>> &memo) {
        if (n % 2 == 0) return {}; // N是奇数才有解
        if (memo.count(n)) return memo[n];
        if (n == 1) {
            memo[n] = { new TreeNode(0) };
            return memo[n];
        };
        
        // 以第i节点为根，左右子树[0,i)、(i,N)
        vector<TreeNode *> ans;
        for (int i = 1; i < n - 1; i += 2) { // 注意i+=2步进
            auto left = dfs(i, memo);
            auto right = dfs(n - 1 - i, memo);
            for (auto &t1 : left) {
                for (auto &t2 : right) {
                    auto root = new TreeNode(0);
                    root->left = t1;
                    root->right = t2;
                    ans.push_back(root);
                }
            }
        }
        memo[n] = ans;
        return memo[n];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
