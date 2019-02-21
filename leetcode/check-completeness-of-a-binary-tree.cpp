//
//  check-completeness-of-a-binary-tree
//  https://leetcode.com/problems/check-completeness-of-a-binary-tree/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // bfs，NULL也入队
        bool completed = false;
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (!node) {
                completed = true;
            } else {
                if (completed) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
