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
    unordered_set<int> st;
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    void dfs(TreeNode *root, int val) {
        if (!root) return;
        root->val = val;
        st.insert(val);
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
