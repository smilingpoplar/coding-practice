//
//  convert-sorted-array-to-binary-search-tree
//  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
//  Created by smilingpoplar on 15/5/22.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, (int)nums.size());
    }
private:
    // 将nums[start,end)变为bst
    TreeNode* sortedArrayToBST(const vector<int>& nums, int start, int end) {
        if (start >= end) return NULL;
        int mid = start + (end - start) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, start, mid);
        node->right = sortedArrayToBST(nums, mid + 1, end);
        return node;
    }
};

void print(TreeNode *root) {
    if (!root) return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Solution solution;
    auto root = solution.sortedArrayToBST(nums);
    print(root);
    
    return 0;
}
