//
//  unique-binary-search-trees-ii
//  https://leetcode.com/problems/unique-binary-search-trees-ii/
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

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int lo, int hi) {
        if (lo > hi) return {nullptr};
        // 生成数字i为根的树，lo<=i<=hi，左子树对应[lo,i-1]、右子树对应[i+1,hi]
        vector<TreeNode *> ans;
        for (int i = lo; i <= hi; i++) {
            auto lefts = generateTrees(lo, i - 1);
            auto rights = generateTrees(i + 1, hi);
            for (auto left : lefts) {
                for (auto right : rights) {
                    auto node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};

void print(TreeNode *root) {
    if (!root) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main(int argc, const char *argv[]) {
    Solution solution;
    auto ans = solution.generateTrees(3);
    for (auto root : ans) {
        print(root);
        cout << endl;
    }

    return 0;
}
