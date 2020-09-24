//
//  number-of-good-leaf-nodes-pairs
//  https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
    
    // 已知 distance<=10
    // 各节点记录到其它的距离为d（d<=10）的子树叶节点数
    vector<int> dfs(TreeNode *root, int distance, int &ans) {
        vector<int> dist(distance + 1, 0);
        if (!root) return dist;
        if (!root->left && !root->right) {
            dist[0] = 1;
            return dist;
        }
        auto left = dfs(root->left, distance, ans);
        auto right = dfs(root->right, distance, ans);
        
        for (int dl = 0; dl <= distance; dl++) {
            for (int dr = 0; dr <= distance ; dr++) {
                if (dl + dr + 2 <= distance) {
                    ans += left[dl] * right[dr];
                }
            }
        }
        
        for (int d = 0; d <= distance; d++) {
            if (d + 1 <= distance) {
                dist[d + 1] = left[d] + right[d];
            }
        }
        return dist;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
