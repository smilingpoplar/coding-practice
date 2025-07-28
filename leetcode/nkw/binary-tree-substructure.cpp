//
//  binary-tree-substructure
//  NC273 树的子结构
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool HasSubtree(TreeNode* r1, TreeNode* r2) {
        if (!r1 || !r2) return false;
        if (isSameTree(r1, r2)) return true;
        return HasSubtree(r1->left, r2) || HasSubtree(r1->right, r2);
    }

    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if (!r2) return true;
        if (!r1) return false;
        return (r1->val == r2->val) && isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
    }
};
