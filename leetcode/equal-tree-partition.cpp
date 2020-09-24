//
//  equal-tree-partition
//  https://leetcode.com/problems/equal-tree-partition/
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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> mp; // sum=>count
        int sum = getSum(root, mp);
        if (sum == 0) return mp[0] > 1;
        return sum % 2 == 0 && mp.count(sum / 2);
    }
    
    int getSum(TreeNode *root, unordered_map<int, int> &mp) {
        if (!root) return 0;
        int sum = root->val + getSum(root->left, mp) + getSum(root->right, mp);
        mp[sum]++;
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
