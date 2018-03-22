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
        auto pos = s.find('(');
        if (pos == string::npos) return new TreeNode(stoi(s));
        int val = stoi(s.substr(0, pos));
        auto root = new TreeNode(val);
        
        // 用左括号计数找括号对
        int start = pos;
        int leftCount = 0;
        for (int i = pos; i < s.size(); i++) {
            if (s[i] == '(') leftCount++;
            else if (s[i] == ')') leftCount--;
            
            if (leftCount == 0 && start == pos) { // 第一对括号[start..i]
                root->left = str2tree(s.substr(start + 1, i - start - 1));
                start = i + 1;
            } else if (leftCount == 0) { // 第二对括号
                root->right = str2tree(s.substr(start + 1, i - start - 1));
            }
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
