//
//  path-sum-iii
//  https://leetcode.com/problems/path-sum-iii/
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
/*
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return searchFrom(root, sum)
            + pathSum(root->left, sum) 
            + pathSum(root->right, sum);
    }
    
    int searchFrom(TreeNode *root, int sum) {
        if (!root) return 0;
        return (root->val == sum ? 1 : 0) 
            + searchFrom(root->left, sum - root->val)
            + searchFrom(root->right, sum - root->val);
    }
};
*/

class Solution {
public:
    int pathSum(TreeNode *root, int target) {
        unordered_map<int, int> presum = {{0,1}}; // sum=>count
        int runningSum = 0;
        int ans = 0;
        search(root, target, runningSum, presum, ans);
        return ans;
    }

    void search(TreeNode *root, int target, int runningSum, 
                unordered_map<int, int> &presum, int &ans) {
        if (!root) return;

        // 以当前节点结尾的子数组，希望能找到数组子段和runningSum-toFind=target
        runningSum += root->val;
        int toFind = runningSum - target;
        if (presum.count(toFind)) ans += presum[toFind];

        presum[runningSum]++;
        search(root->left, target, runningSum, presum, ans);
        search(root->right, target, runningSum, presum, ans);
        presum[runningSum]--; // 回溯，为其他搜索路径准备
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
