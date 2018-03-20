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
        return decode(iss, INT_MIN, INT_MAX);
    }
    
    // 利用上下边界[lower, upper]反序列化
    TreeNode* decode(istringstream &iss, int lower, int upper) {
        auto pos = iss.tellg();
        string s;
        iss >> s;
        if (!iss) return NULL;

        int val = stoi(s);
        if (val < lower || val > upper) {
            iss.seekg(pos);
            return NULL;
        }
        
        auto root = new TreeNode(val);
        root->left = decode(iss, lower, val);
        root->right = decode(iss, val, upper);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, const char * argv[]) {
    return 0;
}
