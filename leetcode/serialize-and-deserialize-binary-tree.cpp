//
//  serialize-and-deserialize-binary-tree
//  https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
//
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
    
    void encode(TreeNode *root, ostringstream &oss) {
        if (!root) {
            oss << "x ";
            return;
        } 

        oss << root->val << " ";
        encode(root->left, oss);
        encode(root->right, oss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return decode(iss);
    }
    
    TreeNode* decode(istringstream &iss) {
        string s;
        iss >> s;
        if (s == "x") return NULL;

        auto root = new TreeNode(stoi(s));
        root->left = decode(iss);
        root->right = decode(iss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, const char * argv[]) {
    return 0;
}
