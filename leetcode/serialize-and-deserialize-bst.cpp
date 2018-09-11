//
//  serialize-and-deserialize-bst
//  https://leetcode.com/problems/serialize-and-deserialize-bst/
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        encode(root, oss);
        return oss.str();
    }

    // 和serialize-and-deserialize-binary-tree的区别是，为了更紧凑不再序列化NULL
    void encode(TreeNode *root, ostringstream &oss) {
        if (!root) return;
        oss << root->val << " ";
        encode(root->left, oss);
        encode(root->right, oss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        vector<int> vals;
        int val;
        while (iss >> val) {
            vals.push_back(val);
        }
        return decode(vals, 0, vals.size());
    }
    
    TreeNode* decode(vector<int> &vals, int start, int end) {
        if (start >= end) return NULL;
        int val = vals[start];
        auto root = new TreeNode(val);
        int i = start + 1;
        while (i < end && vals[i] < val) i++;
        root->left = decode(vals, start + 1, i);
        root->right = decode(vals, i, end);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, const char * argv[]) {
    return 0;
}
