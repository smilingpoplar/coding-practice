//
//  path-sum-iii
//  https://leetcode.com/problems/path-sum-iii/
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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return searchFrom(root, sum)
            + pathSum(root->left, sum) 
            + pathSum(root->right, sum);
    }
    
    int searchFrom(TreeNode *root, int sum) {
        if (!root) return 0;
        int ans = 0;
        if (root->val == sum) ans++;
        ans += searchFrom(root->left, sum - root->val);
        ans += searchFrom(root->right, sum - root->val);
        return ans;
    }
};

/*
class Solution {
public:
    int pathSum(TreeNode *root, int target) {
        int runningSum = 0;
        unordered_map<int, int> sumCnt;
        sumCnt[runningSum] = 1; // 初始空集

        int ans = 0;
        search(root, target, runningSum, sumCnt, ans);
        return ans;
    }

    void search(TreeNode *root, int target, int runningSum, 
                unordered_map<int, int> &sumCnt, int &ans) {
        if (!root) return;

        // 以当前节点结尾的子数组，希望能找到数组子段和runningSum-toFind==target
        runningSum += root->val;
        int toFind = runningSum - target;
        if (sumCnt.count(toFind)) ans += sumCnt[toFind];

        sumCnt[runningSum]++;
        search(root->left, target, runningSum, sumCnt, ans);
        search(root->right, target, runningSum, sumCnt, ans);
        sumCnt[runningSum]--; // 回溯，为其他搜索路径准备
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
