//
//  kth-smallest-element-in-a-bst
//  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//
//  Created by smilingpoplar on 15/7/5.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历，O(n)时间
        // 用栈模拟，用current表示调用栈[current,stack]的栈顶
        if (k <= 0) return INT_MIN;
        auto current = root;
        vector<TreeNode *> stack;
        int count = 0;
        while (current || !stack.empty()) {
            if (current) { // 首先访问左子节点
                stack.push_back(current);
                current = current->left;
            } else { // 当current为空时从栈中取节点访问
                current = stack.back();
                stack.pop_back();
                if (++count == k) return current->val;
                current = current->right;
            }
        }
        return INT_MAX;
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
