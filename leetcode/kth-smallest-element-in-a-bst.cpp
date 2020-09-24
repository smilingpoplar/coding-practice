//
//  kth-smallest-element-in-a-bst
//  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 待关注：如果不先O(n)时间预处理bst并在节点中保存leftCount信息，存在O(h)时间查询算法？
/*
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历，复杂度O(k)
        if (k <= 0) return INT_MIN;
        auto curr = root;
        stack<TreeNode *> stk;
        int count = 0;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top(); stk.pop();
            count++;
            if (count == k) return curr->val;
            curr = curr->right;
        }
        return INT_MAX;
    }
};
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 二分搜索，复杂度O(n)
        if (!root || k <= 0) return INT_MIN;
        int leftCount = countNodes(root->left);
        if (k <= leftCount) {
            return kthSmallest(root->left, k);
        } else if (k == leftCount + 1) {
            return root->val;
        } else {
            return kthSmallest(root->right, k - leftCount - 1);
        }
    }
    
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t2r(2);
    t1l.right = &t2r;
    
    Solution solution;
    cout << solution.kthSmallest(&t0, 2);
    
    return 0;
}
