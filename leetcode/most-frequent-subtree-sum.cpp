//
//  most-frequent-subtree-sum
//  https://leetcode.com/problems/most-frequent-subtree-sum/
//
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
        unordered_map<int, int> sumCnt; // sum => cnt
        getSum(root, sumCnt);

        vector<int> ans;
        int maxCnt = 0;
        for (auto &e : sumCnt) {
            if (e.second > maxCnt) {
                ans = { e.first };
                maxCnt = e.second;
            } else if (e.second == maxCnt) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
    
    int getSum(TreeNode *root, unordered_map<int, int> &mp) {
        if (!root) return 0;
        int val = root->val + getSum(root->left, mp) + getSum(root->right, mp);
        mp[val]++;
        return val;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
