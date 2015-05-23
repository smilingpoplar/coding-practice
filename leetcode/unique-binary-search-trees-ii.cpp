//
//  unique-binary-search-trees-ii
//  https://leetcode.com/problems/unique-binary-search-trees-ii/
//
//  Created by smilingpoplar on 15/5/23.
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

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    vector<TreeNode *> generateTrees(int start, int end) {
        if (start > end) return { NULL };
        // 生成以数字i为根的树，需要两两搭配数字[start,i-1]生成的树和数字[i+1,end]生成的树，start<=i<=end
        vector<TreeNode *> result;
        for (int i = start; i <= end; ++i) {
            auto lefts = generateTrees(start, i - 1);
            auto rights = generateTrees(i + 1, end);
            for (auto left : lefts) {
                for (auto right : rights) {
                    auto iNode = new TreeNode(i);
                    iNode->left = left;
                    iNode->right = right;
                    result.push_back(iNode);
                }
            }
        }
        return result;
    }
};

void print(TreeNode *root) {
    if (!root) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.generateTrees(3);
    for (auto root : result) {
        print(root);
        cout << endl;
    }
    
    return 0;
}
