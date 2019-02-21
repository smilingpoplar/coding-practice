//
//  vertical-order-traversal-of-a-binary-tree
//  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // 题目：节点按列从左到右、再按行从上到下、若位置相同按值从小到大
        // 左右子节点按定义(x-1,y-1)、(x+1,y-1)，y要从大到小排；
        // 可修改定义为(x-1,y+1)、(x+1,y+1)，使y可以从小到大排。
        // dfs遍历，map2d[x][y] = multiset(val)
        map<int, map<int, multiset<int>>> map2d;
        dfs(root, 0, 0, map2d);
        
        vector<vector<int>> ans;
        for (auto &e1 : map2d) {
            auto &mapx = e1.second;
            vector<int> col;
            for (auto &e2 : mapx) {
                auto &sety = e2.second;
                for (int val : sety) {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
    
    void dfs(TreeNode *root, int x, int y, map<int, map<int, multiset<int>>> &map2d) {
        if (!root) return;
        map2d[x][y].insert(root->val);
        dfs(root->left, x - 1, y + 1, map2d);
        dfs(root->right, x + 1, y + 1, map2d);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
