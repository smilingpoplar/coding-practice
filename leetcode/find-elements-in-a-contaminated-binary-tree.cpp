//
//  maximal-square
//  https://leetcode.com/problems/maximal-square/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class FindElements {
    TreeNode* _root;
public:
    FindElements(TreeNode* root) {
        _root = root;
        dfs(root, 0);
    }
    
    void dfs(TreeNode *root, int val) {
        if (!root) return;
        root->val = val;
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }
    
    bool find(int target) {
        // 反向搜索的路径
        stack<int> stk;
        while (target) {
            stk.push(target);
            target = (target - 1) / 2;
        }
        stk.push(0);
        
        return find(_root, stk);
    }
    
    bool find(TreeNode *root, stack<int> &stk) {
        if (stk.empty()) return true;
        if (!root) return false;
        if (root->val != stk.top()) return false;
        stk.pop();
        return find(root->left, stk) || find(root->right, stk);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
