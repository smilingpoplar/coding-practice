//
//  convert-sorted-array-to-binary-search-tree
//  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, (int)nums.size() - 1);
    }
    
    TreeNode* convert(const vector<int>& nums, int low, int high) {
        if (low > high) return NULL;
        int mid = low + (high - low) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = convert(nums, low, mid - 1);
        root->right = convert(nums, mid + 1, high);
        return root;
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
