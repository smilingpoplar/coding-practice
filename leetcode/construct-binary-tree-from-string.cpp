//
//  construct-binary-tree-from-string
//  https://leetcode.com/problems/construct-binary-tree-from-string/
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
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        // 分三部分：‘(’前的数字、第一对"()"、第二对"()"
        auto idx = s.find('(');
        if (idx == string::npos) return new TreeNode(stoi(s));
        int val = stoi(s.substr(0, idx));
        auto root = new TreeNode(val);
        
        // 用左括号计数找括号对
        int start = idx;
        int leftCnt = 0;
        for (int i = idx; i < s.size(); i++) {
            if (s[i] == '(') leftCnt++;
            else if (s[i] == ')') leftCnt--;
            
            if (leftCnt == 0) { // 找到括号对
                if (start == idx) { // 第一对
                    root->left = str2tree(s.substr(start + 1, i - start - 1));
                    start = i + 1;
                } else {  // 第二对
                    root->right = str2tree(s.substr(start + 1, i - start - 1));
                }
            }
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
