//
//  construct-quad-tree
//  https://leetcode.com/problems/construct-quad-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) return NULL;
        return dfs(grid, 0, 0, grid.size());
    }
    
    Node* dfs(vector<vector<int>>& grid, int r1, int c1, int n) {
        // 值全相同的是叶子节点
        bool isLeaf = hasSameValues(grid, r1, c1, n);
        if (isLeaf) return new Node(grid[r1][c1], true, NULL, NULL, NULL, NULL);
        
        int half = n / 2;
        auto tl = dfs(grid, r1, c1, half);
        auto tr = dfs(grid, r1, c1 + half, half);
        auto bl = dfs(grid, r1 + half, c1, half);
        auto br = dfs(grid, r1 + half, c1 + half, half);
        return new Node(false, false, tl, tr, bl, br);
    }  
    
    bool hasSameValues(vector<vector<int>>& grid, int r1, int c1, int n) {
        int val = grid[r1][c1];
        for (int r = r1; r < r1 + n; r++) {
            for (int c = c1; c < c1 + n; c++) {
                if (grid[r][c] != val) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
