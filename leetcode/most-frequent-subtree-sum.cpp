//
//  most-frequent-subtree-sum
//  https://leetcode.com/problems/most-frequent-subtree-sum/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumToCount;
        postOrder(root, sumToCount);
        vector<int> ans;
        int maxCount = 0;
        for (auto &e : sumToCount) {
            if (e.second > maxCount) {
                ans = { e.first };
                maxCount = e.second;
            } else if (e.second == maxCount) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
    
    int postOrder(TreeNode *root, unordered_map<int, int> &mp) {
        if (!root) return 0;
        int val = root->val + postOrder(root->left, mp) + postOrder(root->right, mp);
        mp[val]++;
        return val;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.generate(10);
    for (const auto &row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
