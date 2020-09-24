//
//  maximum-depth-of-n-ary-tree
//  https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
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
    int maxDepth(Node* root) {
        if (!root) return 0;
        int ans = 0;
        for (auto child : root->children) {
            ans = max(ans, maxDepth(child));
        }
        return ans + 1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
