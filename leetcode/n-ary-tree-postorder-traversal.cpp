//
//  n-ary-tree-postorder-traversal
//  https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    int val;
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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node *> stk;
        if (root) stk.push(root);
        while (!stk.empty()) {
            auto top = stk.top(); stk.pop();
            ans.push_back(top->val);
            for (auto child : top->children)
                stk.push(child);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    return 0;
}
