//
//  number-of-islands-ii
//  https://leetcode.com/problems/number-of-islands-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        const vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        // 并查集
        vector<int> parent(m * n, -1);
        vector<int> ans;
        int count = 0;
        for (auto &pos : positions) {
            int r = pos.first, c = pos.second, curr = r * n + c;
            if (parent[curr] == -1) {
                parent[curr] = curr;
                count++;
                for (auto &dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1], next = nr * n + nc;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || parent[next] == -1) continue;
                    // unite curr & next
                    int px = find(curr, parent), py = find(next, parent);
                    if (px != py) {
                        parent[px] = py;
                        count--;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }

    int find(int x, vector<int> &parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    } 
};

int main(int argc, const char * argv[]) {
    return 0;
}
