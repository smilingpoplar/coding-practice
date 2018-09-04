//
//  n-ary-tree-level-order-traversal
//  https://leetcode.com/problems/n-ary-tree-level-order-traversal/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node *> Q;
        if (root) Q.push(root);
        while (!Q.empty()) {
            int sz = Q.size();
            vector<int> row;
            for (int i = 0; i < sz; i++) {
                auto top = Q.front(); Q.pop();
                row.push_back(top->val);
                for (auto child : top->children)
                    if (child) Q.push(child);                
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
