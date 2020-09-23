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
        queue<TreeNode *> q;
        q.push(root);

        // BFS，在弹出NULL后不应再有实际节点
        bool seenNull = false;
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (!node) {
                seenNull = true;
            } else {
                if (seenNull) return false;
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
