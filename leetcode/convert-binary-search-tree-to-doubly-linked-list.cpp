//
//  convert-binary-search-tree-to-doubly-linked-list
//

#include <iostream>
#include <vector>

using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* root) {
        if (!root) return nullptr;
        auto p = root;
        while (p->left) {
            p = p->left;
        }

        TreeNode* prev = nullptr;
        inorder(root, prev);
        return p;
    }

    void inorder(TreeNode* root, TreeNode*& prev) {
        if (!root) return;
        inorder(root->left, prev);
        if (prev) prev->right = root;
        root->left = prev;
        prev = root;
        inorder(root->right, prev);
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
