//
//  number-of-islands-ii
//  https://leetcode.com/problems/number-of-islands-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    class UnionFind {
        vector<int> parent;
        int cnt = 0;
    public:
        UnionFind(int sz) : parent(sz, -1) {
        }
        
        void add(int x) {
            if (parent[x] != -1) return;
            parent[x] = x;
            cnt++;
        }

        int find(int x) {
            if (parent[x] == -1) return -1;
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            parent[py] = px;
            cnt--;
        }
        
        int count() {
            return cnt;
        }
    };
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind uf(m * n);
        const vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<int> ans;
        for (auto &pos : positions) {
            int r = pos.first, c = pos.second, curr = r * n + c;
            uf.add(curr);
            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1], next = nr * n + nc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || uf.find(next) == -1) continue;
                uf.unite(curr, next);
            }
            ans.push_back(uf.count());
        }
        return ans;
    }  
};

int main(int argc, const char * argv[]) {
    return 0;
}
