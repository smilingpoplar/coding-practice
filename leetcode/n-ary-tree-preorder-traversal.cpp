//
//  n-ary-tree-preorder-traversal
//  https://leetcode.com/problems/n-ary-tree-preorder-traversal/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node *> stk;
        if (root) stk.push(root);
        while (!stk.empty()) {
            auto top = stk.top(); stk.pop();
            ans.push_back(top->val);
            for (int i = (int)top->children.size() - 1; i >= 0; i--)
                stk.push(top->children[i]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
