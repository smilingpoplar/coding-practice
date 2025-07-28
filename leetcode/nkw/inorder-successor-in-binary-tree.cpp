//
//  inorder-successor-in-binary-tree
//  NC279 二叉树的下一个结点
//

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* parent;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* node) {
        if (!node) return nullptr;
        if (node->right) {  // 右子树的最左节点
            auto curr = node->right;
            while (curr->left) {
                curr = curr->left;
            }
            return curr;
        }

        while (node->parent && node == node->parent->right) {
            node = node->parent;
        }
        return node->parent;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
