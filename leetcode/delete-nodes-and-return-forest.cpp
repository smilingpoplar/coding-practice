//
//  delete-nodes-and-return-forest
//  https://leetcode.com/problems/delete-nodes-and-return-forest/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDel;
        for (int d : to_delete) {
            toDel.insert(d);
        }
        vector<TreeNode*> ans;
        delNode(root, toDel, true, ans);
        return ans;
    }
    
    TreeNode* delNode(TreeNode *root, unordered_set<int> &toDel, bool isRoot, vector<TreeNode*> &ans) {
        if (!root) return nullptr;
        bool delRoot = toDel.count(root->val);
        if (!delRoot && isRoot) ans.push_back(root);
        
        root->left = delNode(root->left, toDel, delRoot, ans); // 当前节点删除后子节点变新树的根
        root->right = delNode(root->right, toDel, delRoot, ans);
        return delRoot ? nullptr : root;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
